// chanxiao.c  ��ɽ����

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage,neili,vf;
        if( me->is_busy())
         return notify_fail(HIC"��Хʱ�뼯�о�����\n"NOR); 
        if( (int)me->query("max_neili")<400)
            return notify_fail(HIC"�㻹��������������Ϊ��\n"NOR);
        if( (int)me->query("neili") < 300 )
                return notify_fail("�������������\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        skill = me->query_skill("force");
        
        neili=me->query("neili");
        me->add("neili", -100);
        me->receive_damage("qi", 10);

        me->start_busy(6);
        message_vision(
HIY "$N��������һ����������һ����Х�����ɽ�����,���˶���Ŀѣ��\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                vf=ob[i]->query("neili")*ob[i]->query_skill("force");
       damage=(skill*neili-vf)/1000;
       if(damage < 5) damage=5;    
            if(random(skill*neili+vf) < (skill*neili))
                 {
      tell_object(ob[i],HIR"���������������Х�������Ĵ����ߣ����ܵľ�����"+
           "ȥ�����á�����\n"NOR);
      tell_object(ob[i],HIR"���߻���ħ�ˡ�������\n"NOR);
      ob[i]->receive_damage("jing",damage);
      ob[i]->receive_damage("qi",damage);
      ob[i]->receive_wound("jing",damage/2);
      ob[i]->receive_wound("qi",damage/2);
      ob[i]->set("temp/type",random(4));
      ob[i]->apply_condition("zouhuorumo",neili/20);    
                  }     
                else
                 {
                        ob[i]->receive_damage("jing", damage/2 );
                        ob[i]->receive_wound("jing", damage/4);
                        ob[i]->receive_damage("qi",damage/2);
                        ob[i]->receive_wound("qi",damage/2);
tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
                        if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }
                
        }

        return 1;
}
