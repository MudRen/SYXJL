// tan.c ������ - ��
// Written by Doing Lu 1999/1/4

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        object ob;              // ���ֵ�����
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������־�ָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(weapon = me->query_temp("weapon")))
                        return notify_fail("�㲻��ʹ��������\n");

        if (! objectp(ob = target->query_temp("weapon")))
                        return notify_fail("�Է���û���������㲻�õ��ģ�\n");

        if( (int)me->query_skill("liumai-shenjian", 1) < 190 )
                return notify_fail("���������̫���裬����ʹ�á������־���\n");

        if ( me->query("neili") < 500)
                return notify_fail("������������������޷�ʹ�á��⡹�־���\n");
        me->add("neili", -50);

        msg = HIY "$N����һ������ʹ�������񽣡�����ʽ��һ��Ϭ���ޱȵĽ���ֱ��$n��ȥ��\n";

        me->start_busy(2);
        if( random( me->query_skill("force") ) > random((int) target->query_skill("force") ) )
        {
                if (ob->query("item_make"))
                {
                        msg += HIR " $pæ��" + ob->query("name") + "�мܣ�ֻ���û��ھ������ұ����������\n" NOR;
                } else
                {
                        msg += HIW " $p��æ�мܣ�ֻ������ž����һ����$p���е�" + ob->name()
                                + "�Ѿ���Ϊ���أ��������죡\n" NOR;
                        ob->unequip();
                        ob->move(environment(target));
                        ob->set("name", "�ϵ���" + ob->query("name"));
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                }
                target->start_busy(2);
        } else
        {
                msg += "$p������ע" + ob->query("name") + "����$P�����ཻ��ð������⡣\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}


