// niyun.c ��ڤ���� ֮ ����
// by QingP

#include <ansi.h>

int exert(object me, object target)
{
	int meqs, targetqs;
	meqs = me->query_skill("beiming-zhenqi", 1);

        if( !target )
                return notify_fail("�����˭����������\n");

        if( me->is_fighting() || target->is_fighting() )
                return notify_fail("ս������Ҳ��������������\n");

        if(target == me)
                return notify_fail("���޷����Լ���������������\n");

	if( (int)me->query_skill("beiming-zhenqi") < 130 )
		  return notify_fail("��ı�ڤ������Ϊ�������޷����ˡ�\n");

        if( (int)me->query("max_neili") < 200 )
                return notify_fail("���������Ϊ������\n");

        if( (int)me->query("neili") < me->query("max_neili") )
                return notify_fail("�������������\n");

        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 7 )
                return notify_fail( target->name() +
                        "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

        if( (int)target->query("max_neili") > (int)me->query("max_neili") )
                return notify_fail( target->name() +
                        "�������㻹ǿ������ô������������\n");

	     if (target->query_skill("bibo-shengong",1)
		&& target->query_skill("bibo-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("bibo-shengong");
		target->delete_skill("bibo-shengong");
		}

	else if (target->query_skill("beiming-shengong",1)
		&& target->query_skill("beiming-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("beiming-shengong");
		target->delete_skill("beiming-shengong");
		}

	else if (target->query_skill("bahuang-gong",1)
		&& target->query_skill("bahuang-gong",1)
		< meqs)
		{
		targetqs = target->query_skill("bahuang-gong");
		target->delete_skill("bahuang-gong");
		}

	else if (target->query_skill("hamagong",1)
		&& target->query_skill("hamagong",1)
		< meqs)
		{
		targetqs = target->query_skill("hamagong");
		target->delete_skill("hamagong");
		}

	else if (target->query_skill("beiming-zhenqi",1)
		&& target->query_skill("beiming-zhenqi",1)
		< meqs)
		{
		targetqs = target->query_skill("beiming-zhenqi");
		target->delete_skill("beiming-zhenqi");
		}

	else if (target->query_skill("huntian-qigong",1)
		&& target->query_skill("huntian-qigong",1)
		< meqs)
		{
		targetqs = target->query_skill("huntian-qigong");
		target->delete_skill("huntian-qigong");
		}

	else if (target->query_skill("hunyuan-yiqi",1)
		&& target->query_skill("hunyuan-yiqi",1)
		< meqs)
		{
		targetqs = target->query_skill("hunyuan-yiqi");
		target->delete_skill("hunyuan-yiqi");
		}

	else if (target->query_skill("longxiang",1)
		&& target->query_skill("longxiang",1)
		< meqs)
		{
		targetqs = target->query_skill("longxiang");
		target->delete_skill("longxiang");
		}

	else if (target->query_skill("jiuyang-shengong",1)
		&& target->query_skill("jiuyang-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("jiuyang-shengong");
		target->delete_skill("jiuyang-shengong");
		}

	else if (target->query_skill("taiji-shengong",1)
		&& target->query_skill("taiji-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("taiji-shengong");
		target->delete_skill("taiji-shengong");
		}

	else if (target->query_skill("xiaowuxiang",1)
		&& target->query_skill("xiaowuxiang",1)
		< meqs)
		{
		targetqs = target->query_skill("xiaowuxiang");
		target->delete_skill("xiaowuxiang");
		}

	else if (target->query_skill("yunlong-shengong",1)
		&& target->query_skill("yunlong-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("yunlong-shengong");
		target->delete_skill("yunlong-shengong");
		}

	else if (target->query_skill("zixia-shengong",1)
		&& target->query_skill("zixia-shengong",1)
		< meqs)
		{
		targetqs = target->query_skill("zixia-shengong");
		target->delete_skill("zixia-shengong");
		}
	else if ( !target->query_skill("bibo-shengong",1)
	&& !target->query_skill("beiming-shengong",1)
	&& !target->query_skill("bahuang-gong",1)
	&& !target->query_skill("hamagong",1)
	&& !target->query_skill("beiming-zhenqi",1)
	&& !target->query_skill("huntian-qigong",1)
	&& !target->query_skill("hunyuan-yiqi",1)
	&& !target->query_skill("longxiang",1)
	&& !target->query_skill("jiuyang-shengong",1)
	&& !target->query_skill("taiji-shengong",1)
	&& !target->query_skill("xiaowuxiang",1)
	&& !target->query_skill("yunlong-shengong",1)
	&& !target->query_skill("zixia-shengong",1) )
		targetqs = 0;

	else return notify_fail("��������ܵ�" + target->name() + "���������ĵ��ƣ��޷����ˡ�\n");

        message_vision(
                HIY "$N����һЦ��ͻȻ���ΰ����ڰ����һ�����ͷ�½��ϵĵ���������\n"
                + "�Դ�����$n��ͷ������������Ǻ��������ӡ�\n\n"
		NOR, me, target );

	tell_object( target,
		HIG "��ͻ�������ϡ��ٻ�Ѩ������ϸϸһ����������������ֻ���Ժ����������ȣ�\n"
		+ "��ʱ��ͷ�����ͣ��Կ���Ҫը������һ�㣬������һ·������ȥ.......\n"
		+ "����Ƭʱ������Ҳ���Ͳ�ס�������˹�ȥ��\n");

	target->set("jiali", 0);
	target->set("max_neili", me->query("max_neili"));
	target->set("neili", me->query("max_neili"));
	target->set_skill("beiming-zhenqi", (meqs - targetqs)*7/10 );

	me->set("max_neili", 0);
	me->set("neili", 0);
	me->set_skill("beiming-zhenqi", (meqs - targetqs)*3/10 );

	me->set("jiali", 0);

	me->start_busy(13);
	
	target->unconcious();

	return 1;
}