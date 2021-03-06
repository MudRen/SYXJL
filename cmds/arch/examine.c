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
                return notify_fail("你没有权力使用这个指令。\n");

        if (!arg)
                return notify_fail("指令格式：examine [-u] <玩家ID> | -all\n");

        if (! sscanf(arg, "-u %s", arg))
                copy_user = 0;
        else
                copy_user = 1;

        if (arg == "-all" && find_call_out("search_dir") != -1)
        {
                if (run_user && run_user != me)
                        return notify_fail("当前" + run_user->query("name") +
                                           "(" + run_user->query("id") + ")" +
                                           "正在使用该指令进行查找，请稍候再使用。\n");
                remove_call_out("search_dir");
        }

        seteuid(getuid());
        if (arg != "-all")
        {
                string r;
                r = examine_player(arg, copy_user);
                if (! r) r = sprintf("这位玩家(%s)的数据没有异常。\n", arg);
                write("检查结果：" + r);
                return 1;
        }

        count = 0;
        dir = get_dir(DATA_DIR + "login/");
        i = 0;
        result = ({ });
        call_out("search_dir", 0, count, dir, i, me, result);
        write(HIG "现在系统将检查所有玩家，稍后汇报。\n"
              HIG "进度：" + process_bar(0) + "\n");
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
                       HIC "\n查找所有玩家的结果如下：\n" NOR WHT;
                for (i = 0; i < sizeof(result); i++)
                {
                        info += result[i];
                        if (i % 20)
                        {
                                message("system", info, me);
                                info = "";
                        }
                }
                info += HIG "共有 " + to_chinese(count) + " 位玩家数据可能异常。\n\n" NOR;
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
                                  HIG "进度：" + process_bar(i * 100 / sizeof(dir)) +
                                  "\n" HIR "执行中" NOR "> ", me);
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
        if (s1 == "") s1 = "无名";
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
                return sprintf(WHT "没有玩家(%s)。\n" NOR, name);
        }
        if (login_ob->query("id") != name)
        {
                string id;
                id = login_ob->query("id");
                destruct(login_ob);
                return sprintf(HIR "玩家(%s)的ID(%s)不正确。\n" NOR, name, id);
        }

        if (! objectp(user_ob = find_player(name)))
        {
                online = 0;
                user_ob = LOGIN_D->make_body(login_ob);
                if (! user_ob)
                {
                        destruct(login_ob);
                        return sprintf(HIR "无法生成玩家(%s)。\n" NOR, name);
                }

                if (! user_ob->restore())
                {
                        destruct(login_ob);
                        destruct(user_ob);
                        return sprintf(HIR "无法读取玩家(%s)的档案。\n" NOR, name);
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
                                 (interactive(user_ob) ? query_ip_number(user_ob) : "断线中"),
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
                        message_vision("$N口中念念有词，将$n变了出来。\n",
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
                        write("玩家目前正在线上。\n");
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
                
        
        if (gold < 0) return HIR "超过 20000 两黄金" NOR
        // trans to gol
        gold /= 10000
        age = ob->query("mud_age") / 86400
        exp = ob->query("combat_exp")
        if (exp < 1000000 && gold >= 3000
                return HIC "经验 1M 以内超过 3000 两黄金" NOR
        if (gold > 20000
                return HIY "超过 20000 两黄金" NOR
        if (exp > 10000 && (sp = exp / (ob->query("mud_age") / 60 + 1)) > 120
                return HIR "平均经验速度太快(" + sp + "/分钟)" NOR
        if (gold >= 100 && age < 1
                return HIC "14岁金钱超过 100 两黄金" NOR
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
                
                case "，"
                case "："
                case "“"
                case "”"
                case "。"
                case "、"
                case "！"
                case "；"
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
指令格式：examine [-u] <玩家ID> | -al
查找玩家，判断数据是否正常。如果使用了[-u]参数，则除了检查�
家，还会将不在线上玩家复制出来，以供详细查阅�
判断依据�
1. 经验 1M 以内超过 3000 两黄金�
2. 超过 20000 两黄金�
3. 平均经验速度超过 (120/m)�
4. 14岁金钱超过 100 两黄金�
HEL
    )
        return  1
update examine.c
