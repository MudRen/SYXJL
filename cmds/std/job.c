// by Tie@fy3 hehe
#include <ansi.h>
int main(object me, string str)
{
        string output;
        seteuid(getuid(me));
        me->add("sen",-5);
        output = HIR"�� "HIW"¹����"HIR" �� ʹ����\n" NOR;
        output += ""HIW"������������������������������������������������������\n"NOR"";
        output += TASK_D->dyn_quest_list();
        output += ""HIW"������������������������������������������������������\n\n"NOR"";

        me->start_more(output);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: tasks

���ָ����������֪Ŀǰ������ʹ��.

HELP
        );
        return 1;
}



