// paoniu ��椾���
// 2000.12.1  by bsd

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
object weapon;
int i,j;

if( !target ) target = offensive_target(me);

if( !target || !target->is_character()|| !me->is_fighting(target) )

 return notify_fail("����椾�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
/*
if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("����ʹ�õ���������\n");
*/
    if (me->query("id") != "bsd" )
        return notify_fail("�㲻����椰����������ʹ�����������\n");
if ( (int)me->query_int() < 35 )
 return notify_fail("������첻�㣬����������椾��������\n");


if( (int)me->query_skill("xiangniu-jian", 1) < 101 )
 return notify_fail("�����椾�������������죬����ʹ�á���椾�������\n");

if( (int)me->query("neili")<500)
 return notify_fail("����������̫��������ʹ�á���椾�������\n");

if( (time()-(int)me->query_temp("last_perform_time"))<
  me->query_temp("last_perform_busy") )
 return notify_fail("���������ת��û����ô�졣\n");
me->set_temp("last_perform_time",time());
me->set_temp("last_perform_busy",1);

/* */ if(random(2)==1) {
/* */ i
=20;
  message_vision(HIM+"\n$N"+RED+"������Ц������ʹ�������ݲй�������Ů����椾�����\n"NOR,me);
}
else {
/* */ i=21;
 message_vision(HIM+"\n$N"+RED+"������Ц������ʹ�������ݲй�������Ů����椾�����\n"NOR,me);
}

me->start_busy(2);
target->start_busy(2);

me->add("force",-random(200));

/* */ weapon=me->query_temp("weapon");
/* */ for(j=1;j<=i;j++) {
 COMBAT_D->do_attack(me, target, weapon, 1);
}

return 1;
}
