

inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yin";
}



int valid_enable(string usage) { return usage == "force"; }



int valid_learn(object me)

// need more limit here

{

      int i = (int)me->query_skill("wuji-shengong", 1);

	int t = 1, j;

	for (j = 1; j < i / 10; j++) t *= 2;



	if ((int)me->query_skill("force", 1) < 10)

              return notify_fail("��Ļ����ڹ���򻹲�����\n");



	   if ( me->query_skill("bibo-shengong",1)     

              || me->query_skill("bahuang-gong",1)     

		|| me->query_skill("beimin-shengong",1)

		|| me->query_skill("hamagong",1)

		|| me->query_skill("huagong-dafa",1)

		|| me->query_skill("huntian-qigong",1)

		|| me->query_skill("hunyuan-yiqi",1)

		|| me->query_skill("longxiang",1)

		|| me->query_skill("jiuyang-shengong",1)

		|| me->query_skill("taiji-shengong",1)

		|| me->query_skill("xiaowuxiang",1)

		|| me->query_skill("yunlong-shengong",1)

		|| me->query_skill("xuantian-wuji",1)

		|| me->query_skill("wuji-shengong",1)

		|| me->query_skill("shenyuan-gong",1)

		|| me->query_skill("shenghuo-shengong",1)

		|| me->query_skill("tmdafa",1)

		|| me->query_skill("xixing-dafa",1)

		|| me->query_skill("bibo-shengong",1)

		|| me->query_skill("zixia-shengong",1) )

                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫ�󷨣���\n");

        return 1;

}



int practice_skill(object me)

{

       return notify_fail("��Ԫ��ֻ����ѧ(learn)�������������ȡ�\n");

}



string exert_function_file(string func)

{

       return __DIR__"guiyuan-dafa/" + func;

}
