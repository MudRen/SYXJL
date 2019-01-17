// examine.c

#include <ansi.h>

inherit F_CLEAN_UP;

string fname(object ob);
string examine_player(string name, int copy_user);
string is_illegal(object ob);
string process_bar(int n);
static object run_user = 0;

int main(object me, string arg)
{
        int count;
        string *dir;
        string *result;
        int i;
        int copy_user;

        if (me != this_player(1))
                return notify_fail("ÄãÃ»ÓĞÈ¨Á¦Ê¹ÓÃÕâ¸öÖ¸Áî¡£\n");

        if (!arg)
                return notify_fail("Ö¸Áî¸ñÊ½£ºexamine [-u] <Íæ¼ÒID> | -all\n");

        if (! sscanf(arg, "-u %s", arg))
                copy_user = 0;
        else
                copy_user = 1;

        if (arg == "-all" && find_call_out("search_dir") != -1)
        {
                if (run_user && run_user != me)
                        return notify_fail("µ±Ç°" + run_user->query("name") +
                                           "(" + run_user->query("id") + ")" +
                                           "ÕıÔÚÊ¹ÓÃ¸ÃÖ¸Áî½øĞĞ²éÕÒ£¬ÇëÉÔºòÔÙÊ¹ÓÃ¡£\n");
                remove_call_out("search_dir");
        }

        seteuid(getuid());
        if (arg != "-all")
        {
                string r;
                r = examine_player(arg, copy_user);
                if (! r) r = sprintf("ÕâÎ»Íæ¼Ò(%s)µÄÊı¾İÃ»ÓĞÒì³£¡£\n", arg);
                write("¼ì²é½á¹û£º" + r);
                return 1;
        }

        count = 0;
        dir = get_dir(DATA_DIR + "login/");
        i = 0;
        result = ({ });
        call_out("search_dir", 0, count, dir, i, me, result);
        write(HIG "ÏÖÔÚÏµÍ³½«¼ì²éËùÓĞÍæ¼Ò£¬ÉÔºó»ã±¨¡£\n"
              HIG "½ø¶È£º" + process_bar(0) + "\n");
        me->attach_system();
        run_user = me;
        return 1;
}

void search_dir(int count, string *dir, int i, object me, string *result)
{
        int j;
        string name;
        string info;
        string *ppls;

        if (! objectp(me))
        {
                result = 0;
                return;
        }

        if (! me->is_attach_system())
        {
                run_user = 0;
                result = 0;
                return;
        }

        if (i == sizeof(dir))
        {
                info = ESC + "[256D" + ESC + "[K"
                       HIC "\n²éÕÒËùÓĞÍæ¼ÒµÄ½á¹ûÈçÏÂ£º\n" NOR WHT;
                for (i = 0; i < sizeof(result); i++)
                {
                        info += result[i];
                        if (i % 20)
                        {
                                message("system", info, me);
                                info = "";
                        }
                }
                info += HIG "¹²ÓĞ " + to_chinese(count) + " Î»Íæ¼ÒÊı¾İ¿ÉÄÜÒì³£¡£\n\n" NOR;
                message("system", info, me);
                run_user = 0;
                me->detach_system();
                me->write_prompt();
                result = 0;
                return;
        } else
        {
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                for(j = 0; j < sizeof(ppls); j++)
                {
                        reset_eval_cost();
                        if (sscanf(ppls[j], "%s.o", name)==1)
                        {
                                info = examine_player(name, 0);
                                if (! info) continue;
                                result += ({ info });
                                count++;
                        }
                }
                i++;
                message("system", ESC + "[1A" + ESC + "[256D"
                                  HIG "½ø¶È£º" + process_bar(i * 100 / sizeof(dir)) +
                                  "\n" HIR "Ö´ĞĞÖĞ" NOR "> ", me);
                call_out("search_dir", 0, count, dir, i, me, result);
    }
}

string fname(object ob)
{
        string s1, s2;

        s1 = ob->query("surname");
        s2 = ob->query("purename");
        if (! s1) s1= "";
        if (s2) s1 += s2;
        if (s1 == "") s1 = "ÎŞÃû";
        return s1;
}

// Examine the player, if the player is illegal, I will return
// a detial string, or I will return 0
// If the flag copy_user has been set, I will login the user if
// he is offline
string examine_player(string name, int copy_user)
{
        object me;
        object login_ob;
        object user_ob;
        string result;
        int online;

        login_ob = new(LOGIN_OB);
        login_ob->set("id", name);
        if (! login_ob->restore())
        {
                destruct(login_ob);
                return sprintf(WHT "Ã»ÓĞÍæ¼Ò(%s)¡£\n" NOR, name);
        }
        if (login_ob->query("id") != name)
        {
                string id;
                id = login_ob->query("id");
                destruct(login_ob);
                return sprintf(HIR "Íæ¼Ò(%s)µÄID(%s)²»ÕıÈ·¡£\n" NOR, name, id);
        }

        if (! objectp(user_ob = find_player(name)))
        {
                online = 0;
                user_ob = LOGIN_D->make_body(login_ob);
                if (! user_ob)
                {
                        destruct(login_ob);
                        return sprintf(HIR "ÎŞ·¨Éú³ÉÍæ¼Ò(%s)¡£\n" NOR, name);
                }

                if (! user_ob->restore())
                {
                        destruct(login_ob);
                        destruct(user_ob);
                        return sprintf(HIR "ÎŞ·¨¶ÁÈ¡Íæ¼Ò(%s)µÄµµ°¸¡£\n" NOR, name);
                }
        } else
                online = 1;

        result = is_illegal(user_ob);
        if (result)
        {
                if (online)
                        result = sprintf("%s%-14s%-10s%s%-17s%s%s\n",
                                 WHT,
                                 name,
                                 user_ob->query("name"),
                                 (interactive(user_ob) ? HIC : HIR),
                                 (interactive(user_ob) ? query_ip_number(user_ob) : "¶ÏÏßÖĞ"),
                                 NOR,
                                 result);
                else
                        result = sprintf("%s%-14s%-10s%s%-11s%-6s%s%s\n",
                                 WHT,
                                 name,
                                 user_ob->query("name"),
                                 HIG,
                                 ctime(login_ob->query("last_on"))[0..10],
                                 ctime(login_ob->query("last_on"))[20..24],
                                 NOR,
                                 result);
        }

        destruct(login_ob);
        if (! online)
        {
                // the user is offline
                if (copy_user)
                {
                        me = this_player();
                        // I should login it
                        message_vision("$N¿ÚÖĞÄîÄîÓĞ´Ê£¬½«$n±äÁË³öÀ´¡£\n",
                                       me, user_ob);
                        catch(user_ob->setup());
                        catch(user_ob->restore_autoload());
                        catch(user_ob->move(environment(me)));
                } else
                {
                        // ok. logout the user
                        destruct(user_ob);
                }
        } else
        {
                if (copy_user)
                {
                        // login user? oh, I needn't do it because the
                        // user is online now.
                        write("Íæ¼ÒÄ¿Ç°ÕıÔÚÏßÉÏ¡£\n");
                }
        }

        return result;
}

string is_illegal(object ob)
{
        int gold;
        int age;
        int exp;
        int sp;

        if (wizhood(ob) != "(player)")
                return 0;

        if (ob->query_temp("user_setup"))
                gold = MONEY_D->player_carry(ob);
        else
        {
                mapping list = ([
                        "/clone/money/cash"   : 100000,
                        "/clone/money/gold"   : 10000,
                        "/clone/money/silver" : 100,
                        "/clone/money/coin"   : 1
                ])
                string *autoload
                string item
                int amount
                int i
                // the user is load by another object but not logind
                // or the user maybe failed to login, so I will chec
                // the autoload of the user
                autoload = ob->query_autoload_info()
                gold = ob->query("balance")
                if (autoload) i = sizeof(autoload); else i = 0
                for (--i; i >= 0; i--
                
                        if (sscanf(autoload[i], "%s:%d", item, amount) != 2
                                continue
                        gold += amount * (int)list[item]
                        if (gold < 0) break;    // Too much mone
                
        
        if (gold < 0) return HIR "³¬¹ı 20000 Á½»Æ½ğ" NOR
        // trans to gol
        gold /= 10000
        age = ob->query("mud_age") / 86400
        exp = ob->query("combat_exp")
        if (exp < 1000000 && gold >= 3000
                return HIC "¾­Ñé 1M ÒÔÄÚ³¬¹ı 3000 Á½»Æ½ğ" NOR
        if (gold > 20000
                return HIY "³¬¹ı 20000 Á½»Æ½ğ" NOR
        if (exp > 10000 && (sp = exp / (ob->query("mud_age") / 60 + 1)) > 120
                return HIR "Æ½¾ù¾­ÑéËÙ¶ÈÌ«¿ì(" + sp + "/·ÖÖÓ)" NOR
        if (gold >= 100 && age < 1
                return HIC "14Ëê½ğÇ®³¬¹ı 100 Á½»Æ½ğ" NOR
        return 0
string process_bar(int n
        string sp
        int start
        if (n < 0) n = 0; els
        if (n > 100) n = 100
        sp = "                                                  "
        if (n == 100
        
                sp[22] = '1'
                sp[23] = '0'
                sp[24] = '0'
                sp[25] = '%'
                start = 22
        } els
        if (n >= 10
        
                sp[23] = (n / 10) + '0'
                sp[24] = (n % 10) + '0'
                sp[25] = '%'
                start = 23
        } els
        
                sp[24] = n + '0'
                sp[25] = '%'
                start = 24
        
        n /= 2
        if (start > n
        
                sp = sp[0..start-1] + HIY + sp[start..<0]
                sp = sp[0..n - 1] + BBLU + sp[n..<0]
        } els
        
                sp = sp[0..n - 1] + BBLU + sp[n..<0]
                sp = sp[0..start-1] + HIY + sp[start..<0]
        
        sp = NOR + BCYN + sp
        return sp
// sort a chinese string (must be chinese), align th
// string with then len. the prefix is used when the des
// will be lead by another string or space with length is prefix
string sort_string(string desc, int len, int prefix
        int i
        int l
        int crlen
        string msg
        msg = desc
        l = strlen(desc) + prefix
        crlen = strlen("\n")
        for (i = len; i < l; i += len
        
                switch (msg[i - prefix..i - prefix + 1]
                
                case "£¬"
                case "£º"
                case "¡°"
                case "¡±"
                case "¡£"
                case "¡¢"
                case "£¡"
                case "£»"
                        i += 2
                break
                
                if (i >= l
                
                        msg += "\n"
                        break
                } els
                
                        msg = msg[0..i - prefix - 1] + "\n" + msg[i - prefix..<0]
                        l += crlen
                        i += crlen
                
        
        if (i > l) msg += "\n"
        return msg
object get_object(string name
        object ob
        if (ob = find_object(name)
                return ob
        return load_object(name)
// calculate the color char in a strin
int color_len(string str
        int i
        int extra
        extra = 0
        for (i = 0; i < strlen(str); i++
        
                if (str[i] == ESC[0]
                
                        while((extra++, str[i] != 'm') && i < strlen(str)
                                i++
                
        
        return extra
int  help(object  me
write(@HEL
Ö¸Áî¸ñÊ½£ºexamine [-u] <Íæ¼ÒID> | -al
²éÕÒÍæ¼Ò£¬ÅĞ¶ÏÊı¾İÊÇ·ñÕı³£¡£Èç¹ûÊ¹ÓÃÁË[-u]²ÎÊı£¬Ôò³ıÁË¼ì²éÍ
¼Ò£¬»¹»á½«²»ÔÚÏßÉÏÍæ¼Ò¸´ÖÆ³öÀ´£¬ÒÔ¹©ÏêÏ¸²éÔÄ¡
ÅĞ¶ÏÒÀ¾İ£
1. ¾­Ñé 1M ÒÔÄÚ³¬¹ı 3000 Á½»Æ½ğ¡
2. ³¬¹ı 20000 Á½»Æ½ğ¡
3. Æ½¾ù¾­ÑéËÙ¶È³¬¹ı (120/m)¡
4. 14Ëê½ğÇ®³¬¹ı 100 Á½»Æ½ğ¡
HEL
    )
        return  1
update examine.c
