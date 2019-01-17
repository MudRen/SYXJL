// qlist.c
// make by Luky

inherit F_CLEAN_UP;
varargs string get_all_quest(object me, string arg);
int del_quest(object me, int num);

int main(object me,string arg)
{
        string owner;
        string str;
        int lvl, num;

        me = this_player();
        if( !arg ) {
                return notify_fail("ָ���ʽ��qlist all | <��������> | set <�����ļ���>\n");
                }

        if ( sscanf(arg, "set %s.%d", owner, lvl) == 2 ) {
                me->set_temp("add_quest/owner", owner);
                me->set_temp("add_quest/lvl",lvl);
                write( "���������Կ�ʼ��ѯ"+arg[4..strlen(arg)]+"������\n" );
                return 1;
                }

        if ( arg =="all" && me->query_temp("add_quest")) {
                str = get_all_quest(me);
                me->start_more(str);
                return 1;
                }

        if ( (sscanf(arg, "del %d", num) == 1) && me->query_temp("add_quest")) {
                del_quest(me, num);
                write("ɾ����ɡ�\n");
                return 1;
                }

        if ( me->query_temp("add_quest")) {
                write( "��ѯ���������� " + arg+ " ������\n" );
                str = get_all_quest(me, arg);
                me->start_more(str);
                return 1;
                }

        return notify_fail("ָ���ʽ��qlist all | <��������> | set <�����ļ���>\n");
}

varargs string get_all_quest(object me, string arg)
{
        object qlist;
        mapping *lists;
        int i;
        string str;

        qlist = new (QUEST_OB);
        if ( !qlist )
                return 0;
        qlist->set("quest_owner", me->query_temp("add_quest/owner"));
        qlist->set("quest_lvl", me->query_temp("add_quest/lvl"));
        qlist->restore();

        lists = qlist->query_all_quest();
        i = sizeof(lists);
        str = "��������� " + qlist->query("total_quest") + " ������\n";
        str += "   ������       ���� ��Ҫʱ�� ����exp ����pot �漰npc  ��Ʒ����         ��Ʒ�ļ���\n";
        str += "   ��������������������������������������������������������������������������������\n";
        if ( !arg )
                while(i--){
                        str += sprintf("%-2d %-12s  %2s  %-8d %-8d%-8d%-8s %s %s\n   ����ʱ��:%s\n",
                                       i+1, lists[i]["name"], lists[i]["quest_type"],
                                       lists[i]["quest_time"], lists[i]["exp"],
                                       lists[i]["pot"], lists[i]["quest_target"],
                                       lists[i]["quest_desc"], lists[i]["quest_object"],
                                       chinese_time(6,lists[i]["time"]) );
                        str += "   ��������������������������������������������������������������������������������\n";
                        }
        else while(i--){
                if ( strsrch(lists[i]["name"], arg) >=0 ) {
                        str += sprintf("%-2d %-12s  %2s  %-8d %-8d%-8d%-8s %s %s\n   ����ʱ��:%s\n",
                                       i+1, lists[i]["name"], lists[i]["quest_type"],
                                       lists[i]["quest_time"], lists[i]["exp"],
                                       lists[i]["pot"], lists[i]["quest_target"],
                                       lists[i]["quest_desc"], lists[i]["quest_object"],
                                       chinese_time(6,lists[i]["time"]) );
                        str += "   ��������������������������������������������������������������������������������\n";
                        }
                }
        destruct(qlist);
        return str;
}

int del_quest(object me, int num)
{
        object qlist;
        mapping *lists;

        qlist = new (QUEST_OB);
        if ( !qlist )
                return 0;
        qlist->set("quest_owner", me->query_temp("add_quest/owner"));
        qlist->set("quest_lvl", me->query_temp("add_quest/lvl"));
        qlist->restore();

        lists = qlist->query_all_quest();
        lists -= ({ lists[num-1] });
        qlist->set("list", lists);
        qlist->add("total_quest", -1);
        qlist->save();
        destruct(qlist);
        return 1;
}