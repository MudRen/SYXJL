#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ��"HIY"���齣ָ��"NOR"��\n");

        if(!me->is_fighting())
                return notify_fail(""HIY"���齣ָ��"NOR"ֻ����ս����ʹ�ã�\n");

        if((int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");

/*
        if((int)me->query("family/family_name")!="ȫ���")
                return notify_fail("��Ĳ���ȫ����ӣ�������Ҳ�������һ������֮����\n");
*/

        if((int)me->query("qi") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("quanzhen-jianfa", 1) < 200)
                return notify_fail("���ȫ�潣�����𻹲�����ʹ����һ�л������ѣ�\n");

        weapon=me->query_temp("weapon");
   me->delete("env/brief_message");
   message_vision(HIC"\n$N���н���������������ʹ���ˡ��齣ָ����\n"NOR, me);

   me->set("quanzhen", 7);
   message_vision(HIR"\n����˫��\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->set("quanzhen", 9);
   message_vision(HIY"\nָ���ӡ�\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

   me->set("quanzhen", 8);
   message_vision(HIB"\n�����顣\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->set("quanzhen", 9);
   message_vision(YEL"\nָ���顣\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->set("quanzhen", 6);
   message_vision(MAG"\n�����ġ�\n"NOR, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
   message_vision(HIM"\n$N����һ�����������С�\n"NOR, me, weapon);

   me->delete("quanzhen");

   me->receive_damage("qi", 100);
   me->add("neili", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(3);
   return 1;
}
