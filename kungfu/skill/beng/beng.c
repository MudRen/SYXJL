#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me)
{
	object weapon, weapon2, target;
        string msg;

	me->clean_up_enemy();
	target = me->select_opponent(); 

	if( !me->is_fighting() )
		return notify_fail("�컨ʮ�����������־�ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û���ñ��У����ò��ˡ������־���\n");

	if( (int)me->query_skill("sword") < 50 ||
	    me->query_skill_mapped("sword") != "luohua-jian")
		return notify_fail("��ġ��컨ʮ�������������ң��޷�ʹ�á������־���\n");

	msg = HIY "$N��ס���Σ�����������ʹ���컨���������־�\n" NOR;
	message_vision(msg, me);
	
	if ( random(me->query("str")) > (int)target->query("str")/2 && me->query("combat_exp") > (int)target->query("combat_exp")/4*3 )
//	if ( me->query("str") > (int)target->query("str") )
		{
			msg = HIY"$nֻ���û��ھ�ʹ������";
			msg += weapon2->name();
			msg += "��ʱ����ס���ַ��˳�ȥ��\n" NOR;
			me->add("neili", -150);
			target->start_busy(2);
			weapon2->move(environment(me));
		}

	else 	{
			me->add("neili",-50);
			msg = HIY"����$n������$N����ͼ���������ϼӾ�����
" + weapon2->name() + "��������һ����\n˫�����е�����һ��,�������ķ���һ������\n"NOR;
			me->start_busy(2);
		}

	message_vision(msg, me, target);

	return 1;
}
