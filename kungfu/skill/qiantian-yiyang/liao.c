#include <ansi.h>

int exert(object me, object target)
{
// add by cool for need  meet 一灯     
        if(!me->query("yd_1",1)) return 0;
        if( !target )
                return notify_fail("你要用一阳指为谁疗伤？\n");
        if(target == me)
                return notify_fail("你要用一阳指为谁疗伤？\n");

        if(!me->query_skill("kurong-changong",1))
           if((int)me->query_skill("qiantian-yiyang",1) < 120 )
              return notify_fail("你的乾天一阳功不够娴熟，无法替人疗伤！\n");
        if((int)me->query_skill("yiyang-zhi",1) < 120 )
              return notify_fail("你的一阳指神功不够娴熟，无法替人疗伤！\n");
        if (me->query_skill_prepared("finger") != "yiyang-zhi"
        || me->query_skill_mapped("finger") != "yiyang-zhi")
                return notify_fail("你现在无法使用一阳指替人疗伤！\n");      

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法疗伤！\n");

        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("neili") < 1200 )
                return notify_fail("你的真气不够。\n");

        if( (int)target->query("eff_jing") >= (int)target->query("max_jing") )
                return notify_fail( target->name() + "并没有受伤！\n");
       
        message_vision(
                HIY "\n$N伸出右手食指，微一凝气，便点在$n后脑的风府穴上，一阳指力源源透入。。。\n\n"
                HIW"过了不久，$N头顶冒起丝丝白气，听得嗤嗤声响，纯阳的内力在$n体内循环流动，过了一盏茶时分，才放开手指。
只这片刻之间，$n双颊便有了红晕，脸色看起来也好多了。\n" NOR,
                me, target );

        target->set("eff_jing", (int)target->query("max_jing"));
        target->clear_condition();
        me->set("neili", 0);
        me->add("max_neili", - (5 + random(5)));
    
        return 1;
}
