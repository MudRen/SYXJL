
// jingshi.c ��ʧ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp, jing_wound, eff_jing_wound, neili_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("qishang-quan",1) + me->query_skill("jiuyang-force",1);

        if( !me->is_fighting() )
                return notify_fail("����ʧ����ֻ����ս����ʹ�á�\n");

        if( (int)me->query("neili") < 900 )
                return notify_fail("��������������ߣ�\n");

        if( (int)me->query_skill("cuff") < 150 )
                return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���\n");

        if( (int)me->query_skill("qishang-quan", 1) < 150)
                return notify_fail("������ȭ����Ϊ���������ܹ���ᾫʧ��! \n");

          if( (int)me->query_skill("shenghuo-shengong", 1) < 150)
                return notify_fail(HIM "��ľ���������Ϊ���㣬�������ʹ�þ�ʧ��! \n" NOR);

        if( me->query_skill_mapped("cuff") != "qishang-quan")
                return notify_fail("��û�м�������ȭ���޷����þ�ʧ����\n");

        msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "��ʧ��" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 4;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-300);

                msg = HIG "$N��ȭֻ�������������$n����$N����������һ˲����������$n���ڣ�\n$nֻ�����е�ƣ��������\n"NOR;
                neili_wound = 100 + random(skill);
                if(neili_wound > target->query("neili"))
                        neili_wound = target->query("neili");

                jing_wound = random((int)skill);
                eff_jing_wound = random((int)skill / 3);
                target->receive_wound("jing", jing_wound);
                target->receive_damage("jing", eff_jing_wound);
                me->start_busy(2);
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }
        message_vision(msg, me, target);

        return 1;
}
