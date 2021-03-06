// log.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string msg)
{
        string *lines;

        if( !msg || msg=="" ) {
                help(me);
                return 1;
        }

        lines = explode(msg, "\n");
        for(int i=0; i<sizeof(lines); i++)
                lines[i] = "    " + lines[i];
        msg = implode(lines, "\n") + "\n";

        seteuid(geteuid(me));
        write_file(me->query("cwd") + ".ChangeLog",
                "\n" + ctime(time()) + " By " + capitalize(getuid(me)) + "\n\n" + msg);
        write("Ok.\n");
        return 1;
}

int help(object me)
{
        write(@Help
指令格式: log <msg>

将所做过的改变记录在该目录下的 .ChangeLog 里
如果所要超过的一行, 可用 to log 来记录。
Help
        );
        return 1;
}
