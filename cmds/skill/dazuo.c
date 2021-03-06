// exercise.c
#include <ansi.h>
#include <skill.h>
inherit F_CLEAN_UP;
int exercising(object me);
//int halt_exercise(object me, object who, string why);
int halt_exercise(object me);
int main(object me, string arg)
{
	int exercise_cost;
	object where;
	seteuid(getuid());
	where = environment(me);
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");
	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");
	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("你要花多少气练功？\n");
	if (exercise_cost < 10)
		return notify_fail("你的内功还没有达到那个境界！\n");
	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");
	write("你坐下来运气用功，一股内息开始在体内流动。\n");
	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
        message_vision("$N盘膝坐下，紧闭双目，开始修炼内力。\n", me);
        write(HIW"你心中存想，缓缓催动体内气息运行周天。\n"
                 "只觉体内一股热气直透上来,你进入了一种玄妙的境界......\n"NOR);	
	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}

int exercising(object me)
{
	string force_type,force;
	int exercise_cost = (int)me->query_temp("exercise_cost");
        int neili_gain = 1 + (int)me->query_skill("force") / 5;
	object where=environment(me);
        if (exercise_cost < neili_gain) neili_gain = exercise_cost;
	if (exercise_cost < 1)
		return 0;
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);
	if(where->query("xuanbing"))
 	  me->add("qi", (int)neili_gain/3);
	me->add("qi", -neili_gain);
	if (exercise_cost > 0)
		return 1;
	me->set_temp("pending/exercise", 0);
	message_vision("$N运功完毕，深深吸了口气，站了起来。\n", me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
	        force = me->query_skill_mapped("force");
	        force_type = SKILL_D(force)->query_type();
        	if ( force_type == "yin" )
            		me->add( "yin", 1 );
        	else if ( force_type == "yang" )
           		me->add( "yang", 1 );        			
		if ((int)me->query("max_neili") > (int)me->query_skill("force") * 10) {
			write("你的内力修为似乎已经达到了瓶颈。\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else {
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
                          write(HIG"你的内力增加了！！\n"NOR);
        		call_out( "show_balance", 5, me );                          
		return 0;
		}
	}
}
int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}

void show_balance( object me )
{
    int yin, yang, chazhi;

    yin = me->query( "yin" );
    yang = me->query( "yang" );
    if ( ( yin - yang ) >= 0 )
        chazhi = ( yin - yang );
    else
        chazhi = ( yang - yin );
    if ( me->query( "force_ok" ) ) return;
    if ( yin > 1000 && yang > 1000 && chazhi < 300 )
    {
        tell_object( me, HIW"你突然觉得体内的真气流动不同寻常，体内阴阳二气\n"
                            "正在慢慢地融合......\n"NOR );
        if( random(10) > 8 )
        {
            tell_object( me, HIW"终于，你体内的真气完全汇交融合为一体，只觉得全身\n"
                            "内力充盈，你的内功已经大成了。\n"NOR );   
            me->add( "max_neili", 300 );
            me->set( "neili", me->query("max_neili") );
            me->set( "force_ok", 1 );
        }
    }
    else if ( yin < 1000 && yang < 1000 && yin > 200 && yang > 200 &&
              chazhi < 100 )
    {
        tell_object( me, HIC"在内功精进的同时，你隐隐觉得体内的阴阳二气\n"
                            "似乎在互相冲撞，真气的流动有些不大顺畅。\n"NOR);
    }
    return;
}

int help(object me)
{
        write(@HELP
指令格式 : exercise|dazuo [<耗费「气」的量> 必须多于 10]
运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。
HELP
        );
        return 1;
}

