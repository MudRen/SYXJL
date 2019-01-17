// chanxiao.c  荒山虎吟

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage,neili,vf;
        if( me->is_busy())
         return notify_fail(HIC"长啸时须集中精力。\n"NOR); 
        if( (int)me->query("max_neili")<400)
            return notify_fail(HIC"你还需提高你的内力修为。\n"NOR);
        if( (int)me->query("neili") < 300 )
                return notify_fail("你的内力不够。\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

        skill = me->query_skill("force");
        
        neili=me->query("neili");
        me->add("neili", -100);
        me->receive_damage("qi", 10);

        me->start_busy(6);
        message_vision(
HIY "$N深深吸了一口气，仰天一声长啸，如荒山虎吟�,令人耳鸣目眩。\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                vf=ob[i]->query("neili")*ob[i]->query_skill("force");
       damage=(skill*neili-vf)/1000;
       if(damage < 5) damage=5;    
            if(random(skill*neili+vf) < (skill*neili))
                 {
      tell_object(ob[i],HIR"你觉得体内真气被啸声引得四处乱走，难受的就想死"+
           "去，不好。。。\n"NOR);
      tell_object(ob[i],HIR"你走火入魔了。。。。\n"NOR);
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
tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样ⅵ\n");
                        if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }
                
        }

        return 1;
}
