// ip.c

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob;
        if (!str) return notify_fail("<Syntax>: ip <player id>\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("咦... 有这个人吗?\n");
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail("你没有这种权力。\n");
        write(query_ip_number(ob)+"\n");
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : ip <某人>
HELP
    );
    return 1;
}
