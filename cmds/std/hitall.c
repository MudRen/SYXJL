// hitall.c



#include <ansi.h>



inherit F_CLEAN_UP;



int main(object me, string arg)

{

	object obj, * inv;
        int i;

        

	if( environment(me)->query("no_fight") )

		return notify_fail("这里禁止战斗。\n");



        inv=all_inventory(environment(me));



	if( sizeof(inv) == 0 )

                return notify_fail("你想攻击谁？\n");



	for(i=0;i<sizeof(inv);i++)

	{ 

	        obj=inv[i];



		if( !obj->is_character() )

        	        continue;

		if( obj->is_fighting(me) )

		{

			write("加油！加油！加油！\n");

                	continue;

                }

		if( me->query_temp("hitting") )

		{

			write("加油！加油！加油！\n");

                	continue;

		}

		if( !living(obj) )

		{

			write(obj->name() + "已经这样了你还要打，过分了点吧？\n");

			continue;

		}

		if( obj == me )

                	continue;

		if( (int)obj->query("age") < 15 && userp(obj) )

		{

			write("为了世界更美好，放过小孩子吧.\n");

			continue;

		}

		if( userp(obj) )

		{

			message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);

			me->set_temp("hitting");

			remove_call_out("do_hit");

			call_out("do_hit", 1, me, obj);

			continue;

		}



//		if (obj->query("bihua"))

//      	{

//			write(obj->query("name") + "正在比武，你不能帮忙。\n");

//			continue;

//		}



		if( obj->query("can_speak") ) {

			message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);

			me->fight_ob(obj);

			obj->fight_ob(me);

		} else {

			message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);

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
