// tun.c �μҽ��� -����ɽ�� 
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
                return notify_fail("������ɽ�ӡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (! objectp(ob = target->query_temp("weapon")))
                        return notify_fail("�Է����в�û��������\n");

        if( (int)me->query_skill("duanjia-jian", 1) < 100 )
                return notify_fail("��Ķμҽ������������죬����ʹ�á�����ɽ�ӡ���\n");

        if ( me->query("neili") < 100)
                return notify_fail("������������������޷�ʹ�á�����ɽ�ӡ���\n");
        me->add("neili", -30);

        msg = HIY
"$Nʹ���μҽ����ľ���������ɽ�ӡ������һ�������̡�����"+ weapon->name()+"ֱ��$n�����֡�\n";

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
