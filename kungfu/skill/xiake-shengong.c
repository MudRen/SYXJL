//xiake-shengong   侠客神功--侠客岛上乘内功 
// dts@xkx, cleansword@xkx

inherit FORCE;

string *jingmai=({
  "冲脉",
  "任脉",
  "督脉",
  "带脉",
  "阴维",
  "阳维",
  "阴跤",
  "阳跤",
});

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
        int i, nb, nf, nh, ns, ts;
        nb = (int)me->query_skill("literate", 1);
        nf = (int)me->query_skill("force", 1);
        nh = (int)me->query_skill("xiake-shengong", 1);
        ns = (int)me->query("shen");

        if ( me->query("age") < 15 )
  return notify_fail("侠客神功威力太大，你年纪太小，强自练习会走火入魔的。\n");

        if ( nb < 100 && nb <= nh )
return notify_fail("侠客神功是从‘侠客行’中领悟出来的，你文学的修养太低，还无法领悟更高深的武功。\n");

if ( nf < nh)
return notify_fail("侠客神功以基本内功为基础，你的内功火候不够，还需要再练练。n");

        if ( ns < (nh*100) ) 
return notify_fail("侠客神功追求一种侠者的意境，你的侠义之气不够，还无法体会这种意境。\n");

        if( (nh <=80)&&(me->query("jingmai")<(nh/10)))
return notify_fail("侠客神功每一层都以打通人身上的奇经八脉为基础，你的"+
   jingmai[nh/10-1]+"脉还没打通，无法继续练习。\n");   
        return 1;
}


int practice_skill(object me)
{
        if( (int)me->query("max_neili") < 500)
         return notify_fail("你得进一步提高你的内力。\n");
        if( (int)me->query("qi") < 30 )
                return notify_fail("你的气不够。\n");
        if( (int)me->query("neili") < 10 )
                return notify_fail("你的内力不够。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;

}

string exert_function_file(string func)
{
        return __DIR__"xiake-shengong/" + func;
}