
// sanjiao.c ���������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("qishang-quan",1) + me->query_skill("jiuyang-force",1);

        if( !me->is_fighting() )
                return notify_fail("�������������ֻ����ս����ʹ�á�\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("��������������ߣ�\n");

        if( (int)me->query_skill("cuff") < 200 )
                return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���\n");

        if( (int)me->query_skill("qishang-quan", 1) < 200)
                return notify_fail("������ȭ����Ϊ���������ܹ�������������! \n");

          if( (int)me->query_skill("shenghuo-shengong", 1) < 200)
                  return notify_fail(HIM "���ʥ������Ϊ���㣬�������ʹ�����������! \n" NOR);

        if( me->query_skill_mapped("cuff") != "qishang-quan")
                return notify_fail("��û�м�������ȭ���޷����������������\n");

        msg = HIY "$N����������ͼʹ������ȭ�ܾ��еġ�" HIR "���������" HIY "�������з�����������\n"NOR;
//  ������������Ѿ�ʧ��������ʹ�ã��Ǻǡ�\n"
//        message_combatd(msg, me, target);

        ap = me->query("combat_exp") + skill * 400;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-100);

                msg += HIG "$nֻ������ǰһ���ʹ�����ۡ���һ�����һ����Ѫ��\n"NOR;
                neili_wound = 100 + random(skill);
                if(neili_wound > target->query("neili"))
                        neili_wound = target->query("neili");

                qi_wound = neili_wound / 5;
                if(qi_wound > target->query("qi"))
                        qi_wound = target->query("qi");

                target->add("neili", -neili_wound);
                target->receive_wound("qi", qi_wound);
                target->start_busy(2);
                me->start_busy(random(3));
        }
        else
        {
                msg += HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}
