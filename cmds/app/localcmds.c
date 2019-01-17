// localcmds.c

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        mixed *cmds;
        object ob;
        int i;
        if( !arg ) ob = me;
        else    ob = present(arg, environment(this_player()) );
        if( !ob ) ob = find_player(arg);
        if( !ob ) ob = find_living(arg);
        if( !ob ) return notify_fail("û�������һ����\n");
        cmds = ob->query_commands();
        write(ob->query("name")+"���ϼ����ܵ���Ʒ�����ڵĻ����ṩ����ָ�\n");
        for(i = 0; i<sizeof(cmds); i++) {
                if( cmds[i][2]==ob ) continue;
                printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
        }
                return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��localcmds | localcmds <id>

�г������ϼ����ܵ���Ʒ�����ڵĻ����ṩ������ָ�
TEXT
        );
        return 1;
}

