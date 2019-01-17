// mingyu-shengong.c 冥雨神功
// By sylh and yp

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("yihua-force", 1);

       if ( !wizardp(this_player()) && (me->query("family/family_name") != "移花宫"))
                return notify_fail("你不是移花宫弟子不能使用冥雨神功.\n
                                    要是让两位宫主知道了你可惨了.\n");
    if ( me->query("gender") != "女性")
		return notify_fail("移花宫主最讨厌男人,让她知道了可不得了!\n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学冥雨神功？！\n");

	return 1;
}

int practice_skill(object me)
{
    return notify_fail("冥雨神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
    return __DIR__"mingyu-shengong/" + func;
}
