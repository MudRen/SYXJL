
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int number, size;
        object *tar;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ���С�ʮ��ڤ��ն����\n");

        if((int)me->query("neili") < 1000)
                return notify_fail("�������������\n");

        if((int)me->query("qi") < 300 )
                return notify_fail("�����Ѫ���㣬ʹ����ʮ��ڤ��ն��\n");

        if((int)me->query_skill("liusheng-xinyinliu", 1) <150)
                return notify_fail("����������������𻹲�����\n");

        tar=all_inventory(me);
        size = sizeof(tar); 
        
        
        

        me->add("neili", -10);
        me->receive_damage("qi", 200);

        msg = HIC"
$N������ȣ�ʹ���˷�ѩ�����еľ���----"NOR MAG"��ʮ��ڤ��ն��" NOR HIC"��
����$N��һ�ѽ����ˮ��������������ǵ�ϯ�������������𣬷�ɳ��ʯ��
����а���ɱ���������������һ������һ����ʮ�ֹ⻪��\n
$n�������ذ����޴���أ�\n" NOR;

        ap = me->query_skill("liusheng-xinyinliu", 1);
// + me->query_skill("parry");
        ap = ( ap * ap * ap / (4 * 400) );
// + (int)me->query("qi");
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (4 * 400) );
// + (int)target->query("qi");
        dp = dp*250 + target->query("combat_exp"); 
        if( random((ap + dp)/1000+1) <  dp/1000 ) {
                msg += HIC "$n�þ�ȫ�������������һԾ�����ܹ���������һ���亹��\n\n"NOR;
                message_vision(msg, me, target);
        } else {
                damage = (int)me->query_skill("liusheng-xinyinliu",1) / 20 +
                        (int)me->query("neili") / 50 + random((int)me->query("neili") / 50 ) +
                        (int)me->query("qi") / 50 + random((int)me->query("qi") / 50 );
                msg += RED "ɲ�Ǽ�������Ѫ�ҷɣ�������$n���ñ������ˣ�$nһ�����ģ��Ե��ڵأ���\n" NOR;
                if (number < 10) damage +=random(number+1);
                else damage +=random(10);
                        target->receive_damage("qi", me->query("eff_qi")*damage/350, me);
                        target->receive_damage("jing", me->query("eff_jing")*damage/220, me);
                        target->receive_wound("jing", me->query("eff_jing")*damage/400, me);
                        target->receive_wound("qi", me->query("eff_qi")*damage/300, me);
                        target->unconcious();
                        me->improve_skill("liusheng-xinyinliu", 1, 100);
                message_vision(msg, me, target);
                COMBAT_D->report_max_status(target);
         }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        
        me->start_busy(0);
        return 1;
}

