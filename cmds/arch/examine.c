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
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

        if (!arg)
                return notify_fail("ָ���ʽ��examine [-u] <���ID> | -all\n");

        if (! sscanf(arg, "-u %s", arg))
                copy_user = 0;
        else
                copy_user = 1;

        if (arg == "-all" && find_call_out("search_dir") != -1)
        {
                if (run_user && run_user != me)
                        return notify_fail("��ǰ" + run_user->query("name") +
                                           "(" + run_user->query("id") + ")" +
                                           "����ʹ�ø�ָ����в��ң����Ժ���ʹ�á�\n");
                remove_call_out("search_dir");
        }

        seteuid(getuid());
        if (arg != "-all")
        {
                string r;
                r = examine_player(arg, copy_user);
                if (! r) r = sprintf("��λ���(%s)������û���쳣��\n", arg);
                write("�������" + r);
                return 1;
        }

        count = 0;
        dir = get_dir(DATA_DIR + "login/");
        i = 0;
        result = ({ });
        call_out("search_dir", 0, count, dir, i, me, result);
        write(HIG "����ϵͳ�����������ң��Ժ�㱨��\n"
              HIG "���ȣ�" + process_bar(0) + "\n");
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
                       HIC "\n����������ҵĽ�����£�\n" NOR WHT;
                for (i = 0; i < sizeof(result); i++)
                {
                        info += result[i];
                        if (i % 20)
                        {
                                message("system", info, me);
                                info = "";
                        }
                }
                info += HIG "���� " + to_chinese(count) + " λ������ݿ����쳣��\n\n" NOR;
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
                                  HIG "���ȣ�" + process_bar(i * 100 / sizeof(dir)) +
                                  "\n" HIR "ִ����" NOR "> ", me);
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
        if (s1 == "") s1 = "����";
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
                return sprintf(WHT "û�����(%s)��\n" NOR, name);
        }
        if (login_ob->query("id") != name)
        {
                string id;
                id = login_ob->query("id");
                destruct(login_ob);
                return sprintf(HIR "���(%s)��ID(%s)����ȷ��\n" NOR, name, id);
        }

        if (! objectp(user_ob = find_player(name)))
        {
                online = 0;
                user_ob = LOGIN_D->make_body(login_ob);
                if (! user_ob)
                {
                        destruct(login_ob);
                        return sprintf(HIR "�޷��������(%s)��\n" NOR, name);
                }

                if (! user_ob->restore())
                {
                        destruct(login_ob);
                        destruct(user_ob);
                        return sprintf(HIR "�޷���ȡ���(%s)�ĵ�����\n" NOR, name);
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
                                 (interactive(user_ob) ? query_ip_number(user_ob) : "������"),
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
                        message_vision("$N���������дʣ���$n���˳�����\n",
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
                        write("���Ŀǰ�������ϡ�\n");
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
                
        
        if (gold < 0) return HIR "���� 20000 ���ƽ�" NOR
        // trans to gol
        gold /= 10000
        age = ob->query("mud_age") / 86400
        exp = ob->query("combat_exp")
        if (exp < 1000000 && gold >= 3000
                return HIC "���� 1M ���ڳ��� 3000 ���ƽ�" NOR
        if (gold > 20000
                return HIY "���� 20000 ���ƽ�" NOR
        if (exp > 10000 && (sp = exp / (ob->query("mud_age") / 60 + 1)) > 120
                return HIR "ƽ�������ٶ�̫��(" + sp + "/����)" NOR
        if (gold >= 100 && age < 1
                return HIC "14���Ǯ���� 100 ���ƽ�" NOR
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
                
                case "��"
                case "��"
                case "��"
                case "��"
                case "��"
                case "��"
                case "��"
                case "��"
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
ָ���ʽ��examine [-u] <���ID> | -al
������ң��ж������Ƿ����������ʹ����[-u]����������˼���
�ң����Ὣ����������Ҹ��Ƴ������Թ���ϸ���ġ
�ж����ݣ
1. ���� 1M ���ڳ��� 3000 ���ƽ�
2. ���� 20000 ���ƽ�
3. ƽ�������ٶȳ��� (120/m)�
4. 14���Ǯ���� 100 ���ƽ�
HEL
    )
        return  1
update examine.c
