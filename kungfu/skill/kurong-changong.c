// kurong-changong.c  ��������

inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yang";
}

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
        int nb, nf, nh, ns;
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("kurong-changong", 1);
	ns = (int)me->query("guilty");

       	if ( me->query("couple/have_couple") )
        	return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ����������\n");

          if ( me->query("gender") == "Ů��" )
		return notify_fail("���ͯ��֮�壬������ϰ����������\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷���������Ŀ���������\n");

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�������������\n");

	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷���������Ŀ���������\n");

        if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ���������������������Ŀ���������\n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
//      || me->query_skill("kurong-changong",1) 
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
        || me->query_skill("xixing-dafa",1)
        || me->query_skill("jiuyang-force",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧϰ������������\n");

	return 1;
}


int practice_skill(object me)
{
     	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return "/kungfu/skill/kurong-changong/" + func;
}
