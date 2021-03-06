// jiuyangforce.c

inherit FORCE;



mapping *action = ({

        ([      "action":

"$N使出一招「三重天地混元」，左手聚出一团混元真气击向$n的$l",

                "force":                300,

                "damage_type":  "瘀伤"

        ]),

        ([      "action":

"$N使出一招「五重天地混元」，右手聚出一团混元真气击向$n的$l",

                "force":                500,

                "damage_type":  "瘀伤"

        ]),

        ([      "action":

"$N使出一招「七重天地混元」，双手由掌变拳，聚出一团混元真气击向$n的$l",

                "force":                700,

                "damage_type":  "瘀伤"

        ]),

        ([      "action":

"$N使出一招「风雷震九州」，全身腾空而起，化作一团混元真气击向$n的$l",

                "force":                1000,

                "damage_type":  "瘀伤"

        ]),

});

mixed hit_ob(object me, object victim, int damage_bonus, int factor)

{

        mixed foo;

        int force;



        foo = ::hit_ob(me, victim, damage_bonus, factor);

        if( intp(foo) && (damage_bonus + foo > 0) ) {

              if( random(3*(me->query_skill("jiuyangforce"))) > (damage_bonus + foo))

                 {

                        victim->receive_wound("qi", (damage_bonus + foo));

                        victim->receive_wound("jing", (damage_bonus + foo));

//                        victim->receive_wound("sen", (damage_bonus + foo));

                        force = victim->query("force");

                        victim->set("force", force-random(10)-1);

                        victim->set("max_force", 0);

                        return

"$N的九阳神功摧毁了$n的真元！！！！\n";

                }

        }

        return foo;

}



int valid_enable(string usage) 

{ 

return  usage=="iron-cloth" ||

        usage=="unarmed" ||

        usage=="parry"||

        usage=="force";

}



//int valid_learn(object me) { return 1; }



int valid_learn(object me)

{

if ((int)me->query("max_neili") < 500)

                return notify_fail("你的内力不够。\n");

     if ((int)me->query("combat_exp") < 100000)

                return notify_fail("你的能力还没达到学九阳神功的地步。 \n");

        return 1;

}

int practice_skill(object me)

{

        return 

notify_fail("九阳神功只能用学的，或是从运用(exert)中增加熟练度。\\n");

}



int effective_level() { return 21; }

//int effective_level() { return 50;}



string *absorb_msg = ({

        "$n身体虚转，双手微划，无坚不摧的九阳神功澎湃而出。\n",

        "$n施展出九阳神功，浑身肌肤坚如寒铁。\n",

        "$n身型微展，九阳神功充斥了丈许空间。\n",

});



string query_absorb_msg()

{

        return absorb_msg[random(sizeof(absorb_msg))];

}

mapping query_action(object me, object weapon)

{

        return action[random(sizeof(action))];

}

string *unarmed_parry_msg = ({

        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",

        "$n长袖一甩，一股大力将$N送出丈外。\n",

        "$n施展出「混元无我」，轻描淡写的化解了$N的攻势。\n",

});

string *parry_msg = ({

        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",

        "$n长袖一甩，一股大力将$N送出丈外。\n",

        "$n施展出「九阳无我」，轻描淡写的化解了$N的攻势。\n",

});

string query_parry_msg(object weapon)

{

        if( weapon )

                return parry_msg[random(sizeof(parry_msg))];

        else

                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];

}

string exert_function_file(string func)

{

        return CLASS_D("mingjiao") + "/jiuyangforce/" + func;

}

int bounce_ratio()

{

        return 40;

}



int learn_bonus()

{

        return -100;

}

int practice_bonus()

{

        return -500;

}

int black_white_ness()

{

        return 200;

}



