inherit FORCE;

inherit F_DBASE;
public string query_type() {
       return "yin";
}


int valid_enable(string usage) { return usage=="force"; }



int valid_learn(object me)

{

	int lvl = (int)me->query_skill("beiming-shengong", 1);



	if ( me->query("gender") == "无性" && lvl > 49)

		return notify_fail("你无根无性，阴阳不调，难以领会高深的北冥神功。\n");



          if ( me->query_skill("yunu-xinjing",1)
//	|| me->query_skill("beiming-shengong",1)

//	|| me->query_skill("bahuang-gong",1)

	|| me->query_skill("hamagong",1)

	|| me->query_skill("huagong-dafa",1)

	|| me->query_skill("huntian-qigong",1)

	|| me->query_skill("hunyuan-yiqi",1)

	|| me->query_skill("longxiang",1)

	|| me->query_skill("jiuyang-shengong",1)

	|| me->query_skill("taiji-shengong",1)

	|| me->query_skill("xiaowuxiang",1)

	|| me->query_skill("yunlong-shengong",1)

        || me->query_skill("jiuyang-force",1)
        || me->query_skill("kurong-changong",1)
        || me->query_skill("xuantian-wuji",1)
        || me->query_skill("guiyuan-dafa",1)
	|| me->query_skill("zixia-shengong",1) )

		return notify_fail("你不先散了别派内功，怎能学吸星大法？！\n");



	return 1;

}



int practice_skill(object me)

{

    return notify_fail("吸星大法只能用学的，或是从运用(exert)中增加熟练度。\n");

}



string exert_function_file(string func)

{

    return __DIR__"xixing-dafa/" + func;

}
