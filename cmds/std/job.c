// by Tie@fy3 hehe
#include <ansi.h>
int main(object me, string str)
{
        string output;
        seteuid(getuid(me));
        me->add("sen",-5);
        output = HIR"◎ "HIW"鹿鼎记"HIR" ◎ 使命榜\n" NOR;
        output += ""HIW"———————————————————————————\n"NOR"";
        output += TASK_D->dyn_quest_list();
        output += ""HIW"———————————————————————————\n\n"NOR"";

        me->start_more(output);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: tasks

这个指令是用来得知目前的所有使命.

HELP
        );
        return 1;
}



