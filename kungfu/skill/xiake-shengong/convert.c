// heal.c

#include <ansi.h>
#include <cond.h>

int exert(object me, object target)
{
 string *poison;
 int i; 
        if( me->is_fighting() )
            {
              if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail(HIR"在战斗中运功化毒会引起走火入魔！\n"NOR);
             }
        if ((int)me->query_skill("xiake-shengong", 1) < 40)
                return notify_fail("你的侠客神功火候不够。\n");
        if( (int)me->query("neili") < 400 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 4 )
            {
              if(test_zouhuorumo(me)) return notify_fail("");
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
             }
      if(! can_convert(me))
      return notify_fail(HIC"你目前体内并没有可以转换成内力毒药。\n"NOR);
      poison=keys(my_cond);
     for(i=0;i<sizeof(poison);i++)
      {
        me->apply_condition(poison[i],0);
        }
      tell_object(me,HIC"你开始运动侠客神功化解体内的毒药。\n"NOR);
      tell_object(me,HIY"毒药的转换时间视你所中的毒药毒性而定，可能\n"NOR);
    tell_object(me,HIY"需要较长时间，在这期间内你不能enforce你的内力\n"NOR);
    tell_object(me,HIY"同时必须保证 你有充足的内力，否则可能引起\n"NOR);
    tell_object(me,HIY"走火入魔。\n"NOR);
    me->set("jiali",0);
    me->apply_condition("convert",my_cond);  
        return 1;
}
