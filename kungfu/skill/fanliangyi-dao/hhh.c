//˫���ͱ�

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

//int valid_enable(string usage) { return usage=="array"; }

//int form_array(object leader)
int perform(object leader, object target)
{
        object *member,ob, weapon,obj;
        int i,j,n;
        int max,min,skill;
        object *t;
        if( !target ) target = offensive_target(leader);
        if( !target
        ||      !target->is_character()
        ||      !leader->is_fighting(target) )
                return notify_fail( "��˫���ͱڡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        member = leader->query_team();
        if( sizeof(member) != 2 )
                return notify_fail("�����ǵ��������ˣ���һ����һ�������С�\n");

        j=sizeof (member);
        for (i=0;i<j;i++)
        {
                ob=member[i];
                if (!ob||!living(ob)||!ob->is_character())
                {
                        return notify_fail("�����˭ͬʹ�����ǵ���\n");
                }
                if (ob->query_temp("array/name"))
                {
                        return notify_fail("�Ѿ���ɵ����ˡ�\n");
                }
                if (environment(leader)!=environment(ob))
                {
                        return notify_fail("�����������ˡ�\n");
                }
                if (!ob->query_skill("fanliangyi-dao",1))
                {
                        return notify_fail(ob->name()+"�����ᷴ���ǵ�����\n");
                }
                if (ob->is_ghost())
                {
                        return notify_fail("ֻ��������˲����鵶��\n");
                }

                if( (int)ob->query("max_neili") < 300 )
                        return notify_fail(ob->query("name")+"������������\n");

                if( (string)ob->query_skill_mapped("force")!= "zixia-shengong")
                        return notify_fail(ob->query("name")+"û��ʹ�û�ɽ���ڹ���\n");

                if( !(weapon = ob->query_temp("weapon"))
                ||      (string)weapon->query("skill_type") != "blade" )
                        return notify_fail(ob->query("name")+"�����ðѵ���������\n");

                if( (int)ob->query_skill("fanliangyi-dao",1)<100)
                        return notify_fail(ob->query("name")+"�ķ����ǵ���������������\n");

                if( (string)ob->query_skill_mapped("blade")!="fanliangyi-dao")
                        return notify_fail(ob->query("name")+"����ʹ�÷����ǵ�����\n");
        }

//get the average array skill of the team
        n=0;
        for (i=0;i<j;i++)
        {
                ob=member[i];
                n+=(int)ob->query_skill("fanliangyi-dao",1);
        }
        n/=2;

//get the difference of the array skill,
//first get the max and mix skill level of the array
        max=member[0]->query_skill("fanliangyi-dao",1);
        min=max;
        for (i=0;i<j;i++)
        {
                skill=member[i]->query_skill("fanliangyi-dao",1);
                if(skill>max)
                        max=skill;
                else if(skill<min)
                        min=skill;
        }

//and the leader is important
        n += leader->query_skill("fanliangyi-dao", 1) * 2;
        n /= max - min + 1;
        for (i=0;i<j;i++)
        {
                ob=member[i];
                ob->set_temp("no_quit",1);

                ob->set_temp("array/name","fanliangyi-dao");
                ob->set_temp("array/level",n);

                ob->add_temp("apply/attack",n);
                ob->add_temp("apply/defense", n);
                ob->add_temp("apply/damage",n);
                ob->add_temp("apply/armor", n);
        }
        message_vision( HIG "$N����$nվ�����Ƿ�λ����ʱ����֮���Եû�Ȼ��ɡ�����������\n" NOR, leader,ob);
                for(i=0;i<sizeof(t);i++)
        {
        if(t[i]){
                t[i]->set_temp("ttarget",obj->query("id"));
                t[i]->kill_ob(obj);
                obj->kill_ob(t[i]);
                }
        }
 
        return 1;
}

int dismiss_array(object person)
{
        int i,j,n;
        object *member,ob;

        member=person->query_team();
        j=sizeof(member);
        n=person->query_temp("array/level");
        for (i=0;i<j;i++)
        {
                ob=member[i];
                ob->delete_temp("array");
                ob->add_temp("apply/attack",-n);
                ob->add_temp("apply/damage",-n);
                ob->add_temp("apply/defense",-n);
                ob->add_temp("apply/armor", -n);
                tell_object(ob,"�����ɢ��\n");
        }
}

//if the leader kills enemy, then all members in the array kill enemy
int array_kill(object leader, object enemy)
{
        object *member, ob;
        int i,j;
        member=leader->query_team();
        j=sizeof(member);

        for(i=0;i<j;i++) {
                ob=member[i];
                ob->kill_ob(enemy);
        }

        return 1;
}



int effective_level() { return 10;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}

