// sword.cen.c



#include <ansi.h>



inherit SKILL;



int valid_enable(string usage) { return usage=="array"; }



int form_array(object leader)

{

        object *member;



        member = leader->query_team();

        if( sizeof(member) != 7 )

                return notify_fail("������������ˣ���һ����һ�������С�\n")

;

        message_vision( HIG "$N������������վ�����Ƿ�λ������ˡ�������󡹣�\n"

 NOR, leader);

        return 1;

}