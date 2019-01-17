// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( me->query_temp("hitting") )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "�Ѿ��������㻹Ҫ�򣬹����˵�ɣ�\n");


	if(obj==me)	return notify_fail("���Լ�������ô�벻����\n");

	if( (obj->query_temp("begging") || (int)obj->query("age") < 15 ) && userp(obj) )
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

	if( userp(obj) ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : hit <����>

���ָ������ֱ����һ��������С���������ʽ��ս���Ǽ�ʱ�ģ�ֻҪ���һ
��������ս���ͻῪʼ��ֱ��ĳһ������50% ����Ϊֹ�����ָ�����Щ��
ϲ��fight��NPC�����ã���Ϊ�ܶ�ʱ����ı���Ҫ��ᱻ�ܾ���

�������ָ��: fight, kill

HELP
    );
    return 1;
}

