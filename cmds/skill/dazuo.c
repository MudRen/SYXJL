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
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");
	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");
	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("��Ҫ��������������\n");
	if (exercise_cost < 10)
		return notify_fail("����ڹ���û�дﵽ�Ǹ����磡\n");
	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");
	write("�������������ù���һ����Ϣ��ʼ������������\n");
	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
        message_vision("$N��ϥ���£�����˫Ŀ����ʼ����������\n", me);
        write(HIW"�����д��룬�����߶�������Ϣ�������졣\n"
                 "ֻ������һ������ֱ͸����,�������һ������ľ���......\n"NOR);	
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
	message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
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
			write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else {
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
                          write(HIG"������������ˣ���\n"NOR);
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
        tell_object( me, HIW"��ͻȻ�������ڵ�����������ͬѰ����������������\n"
                            "�����������ں�......\n"NOR );
        if( random(10) > 8 )
        {
            tell_object( me, HIW"���ڣ������ڵ�������ȫ�㽻�ں�Ϊһ�壬ֻ����ȫ��\n"
                            "������ӯ������ڹ��Ѿ�����ˡ�\n"NOR );   
            me->add( "max_neili", 300 );
            me->set( "neili", me->query("max_neili") );
            me->set( "force_ok", 1 );
        }
    }
    else if ( yin < 1000 && yang < 1000 && yin > 200 && yang > 200 &&
              chazhi < 100 )
    {
        tell_object( me, HIC"���ڹ�������ͬʱ���������������ڵ���������\n"
                            "�ƺ��ڻ����ײ��������������Щ����˳����\n"NOR);
    }
    return;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise|dazuo [<�ķѡ���������> ������� 10]
�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������
HELP
        );
        return 1;
}

