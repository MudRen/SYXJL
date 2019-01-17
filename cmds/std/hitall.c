// hitall.c



#include <ansi.h>



inherit F_CLEAN_UP;



int main(object me, string arg)

{

	object obj, * inv;
        int i;

        

	if( environment(me)->query("no_fight") )

		return notify_fail("�����ֹս����\n");



        inv=all_inventory(environment(me));



	if( sizeof(inv) == 0 )

                return notify_fail("���빥��˭��\n");



	for(i=0;i<sizeof(inv);i++)

	{ 

	        obj=inv[i];



		if( !obj->is_character() )

        	        continue;

		if( obj->is_fighting(me) )

		{

			write("���ͣ����ͣ����ͣ�\n");

                	continue;

                }

		if( me->query_temp("hitting") )

		{

			write("���ͣ����ͣ����ͣ�\n");

                	continue;

		}

		if( !living(obj) )

		{

			write(obj->name() + "�Ѿ��������㻹Ҫ�򣬹����˵�ɣ�\n");

			continue;

		}

		if( obj == me )

                	continue;

		if( (int)obj->query("age") < 15 && userp(obj) )

		{

			write("Ϊ����������ã��Ź�С���Ӱ�.\n");

			continue;

		}

		if( userp(obj) )

		{

			message_vision("\n$N����$n���һ�������У�\n\n", me, obj);

			me->set_temp("hitting");

			remove_call_out("do_hit");

			call_out("do_hit", 1, me, obj);

			continue;

		}



//		if (obj->query("bihua"))

//      	{

//			write(obj->query("name") + "���ڱ��䣬�㲻�ܰ�æ��\n");

//			continue;

//		}



		if( obj->query("can_speak") ) {

			message_vision("\n$N����$n���һ�������У�\n\n", me, obj);

			me->fight_ob(obj);

			obj->fight_ob(me);

		} else {

			message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);

			me->fight_ob(obj);

			obj->kill_ob(me);

		}

	}

	return 1;

}



void do_hit(object me, object obj)

{

	if(objectp(present(obj, environment(me)))) {

		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );

		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );

	}

	me->delete_temp("hitting");

	return;

}
