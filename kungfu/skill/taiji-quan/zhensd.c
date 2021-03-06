// zhen.c 太极拳「震」字诀
// snowman
#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("神功震敌只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「震」字诀！\n");         
        if( (int)me->query_skill("taiji-quan", 1) < 100 )
                return notify_fail("你的太极拳不够娴熟，不会使用「震」字诀。\n");
        if( (int)me->query_skill("yinyun-ziqi", 1) < 100 )
                return notify_fail("你的氤氲紫气等级不够高，不能用来反震伤敌。\n");
        if( (int)me->query("max_neili", 1) < 1200 )
                return notify_fail("你现在内力太弱，不能使用「震」字诀。\n");                
        if( (int)me->query("neili", 1) < 1200 )
                return notify_fail("你现在真气不够，不能使用「震」字诀。\n");
       
        if (me->query_skill_prepared("cuff") != "taiji-quan"
           || me->query_skill_mapped("cuff") != "taiji-quan")
                return notify_fail("你现在无法使用太极拳「震」字诀进行攻击。\n");                                                                                 
        if (me->query_skill_mapped("parry") != "taiji-quan")
                return notify_fail("你太极拳「震」字诀必须在激发招架的情况下才能使用。\n");                                                                                 
                    
               
        msg = CYN "$N默运神功，使出太极拳"RED"「震」"CYN"字诀，连划数个太极圈绕住$n，企图以本身真力震伤$n！\n"NOR;

        if(me->query("neili") < target->query("neili")){
           me->start_busy(3);
           target->start_busy(3); 
           me->add("qi", -50);
           me->add("neili", -300);
           target->add("qi", -50);
           target->add("neili", -300);
           msg += HIY"结果$p和$P两人内力一拼，双方都没占到丝毫好处！\n"NOR;
           }
        else if(random(me->query_skill("force")) > target->query_skill("force")/2){
                me->start_busy(3);
                target->start_busy(2+random(3));
                
                damage = (int)me->query_skill("force")*2;                
                if(me->query_skill("taiji-quan", 1) > random(target->query_skill("parry", 1)))
                   damage = damage+me->query_skill("taiji-quan", 1);
                if(me->query_skill("taiji-quan", 1) > random(target->query_skill("dodge", 1)))
                   damage = damage+target->query_skill("dodge", 1);                
                if(me->query("neili") > target->query("neili")*2)
                   damage = damage+me->query_skill("force");
                if(damage> 1100) damage = 1100;                

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/4);
                if(target->query("neili") >= damage) {
                   target->add("neili", -(damage/2));
                target->add("qi", -50);
                }
                else {
                target->set("neili", 0);
                me->add("neili", -(damage/3));
                me->add("qi", -50);
                  }
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "震伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";       
                } 
        else{
             me->start_busy(3);
             me->add("qi", -25);
             me->add("neili", -300);
             msg += HIY"可是$p看破了$P的企图，并没有上当。\n"NOR;
             }
        message_vision(msg, me, target);
        return 1;
}
