#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{       
        
        int i, l,q;        
        int t = 1, j;
       for (j = 1; j < i / 10; j++) t *= 2;        
        i = (int)me->query_skill("force", 1);       
        l = (int)me->query_skill("buddhism", 1);       
       q = (int)me->query_skill("qiantian-yiyang", 1);       

        if (!me->query("tls"))
        if (q > 20 && (int)me->query("shen") < t * 100)
        return notify_fail("大理乃是明门正派，看来你的侠义正气还不够啊！\n");

        if (q > 20 && q < 150 && l < q - 10)
        return notify_fail("你的佛学修为看来不能抑止你的心中的好胜之心了！\n");

        if (i < 20)
                 return notify_fail("你的基本内功火候还不够，无法领会乾天一阳功。\n");

        if (i > 99 && (string)me->query("gender") != "男性")
                 return notify_fail("你不是纯阳之身，无法领会更高层的乾天一阳功。\n");

        if ( 
           me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("guiyuan-tunafa",1)
        || me->query_skill("xixing-dafa",1)
        )
        return notify_fail("乾天一阳功怎可和邪派内功混为一体？\n");

        return 1;
}


int practice_skill(object me)
{
            return notify_fail("乾天一阳功只能用学(learn)来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"qiantian-yiyang/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIY + me->name()+"结珈而坐，神态安详。" NOR,
    "start_my_msg" : "你盘膝坐下，闭目合什，运起乾天一阳神功，一股纯阳真气开始在体内运转。\n",
    "start_other_msg" : me->name()+"盘膝坐下，闭目合什,神态安详，周身似乎有一层金光笼罩。\n",
    "halt_msg" : "$N双掌一分，平摊在胸，迅速收气，停止真气的流动。\n",
    "end_my_msg" : "你真气在体内运行了一个周天，缓缓收气于丹田，慢慢睁开了眼睛。\n",
    "end_other_msg" : "只见"+me->name()+"慢慢睁开眼睛，周身笼罩的金光逐渐隐去。\n"
          ]);
}