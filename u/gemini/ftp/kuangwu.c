//kuangwu.c ħ�߿���

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

        if(!me->is_fighting())
              return notify_fail("��ħ�߿��衹ֻ����ս����ʹ�ã�\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������������\n");
       
        if (!objectp(weapon = me->query_temp("weapon"))
            || weapon->query("skill_type") != "staff"
            || me->query_skill_mapped("staff") != "lingshe-zhangfa"
            || me->query_skill_mapped("force") !="hamagong")
                return notify_fail("�������޷�ʹ�á�ħ�߿��衻��\n");

        if(me->query("family/master_name")!="ŷ����")
                return notify_fail("��û�о���ŷ�����ָ�㣬�޷�������еľ��裡\n");

        if((int)me->query_skill("lingshe-zhangfa", 1) < 150)
                return notify_fail("��������ȷ��ȼ��������޷�ʹ�á�ħ�߿��衻��\n");
 
        if((int)me->query_skill("hamagong", 1) < 150)
                return notify_fail("��ĸ�󡹦�ȼ��������޷�ʹ�á�ħ�߿��衻��\n");
             weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N����󡹦��������Ѩ�����з�������������������......�\n"NOR, me);
           message_vision(HIB"\nͻȻֻ��$Nʹ�������ȷ����һ�С�ħ�߿��衻��\n"NOR, me);
              me->set("lingshe", 7);
           message_vision(HIR"\nħ\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

           me->set("lingshe", 9);
           message_vision(HIY"\n��\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

           me->set("lingshe", 8);
           message_vision(HIB"\n��\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

           me->set("lingshe", 9);
           message_vision(MAG"\n��\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
           message_vision(HIW"\n$N�������ع鵤��֮ǰ�����ַ����У�\n"NOR, me, weapon);

           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           message_vision(HIC"\n$N�޷�������Ϣ������ֻ�ú�Ծ���С�\n"NOR, me, weapon);

           me->delete("lingshe");

           me->add("neili", -100);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(4);
   return 1;
}


