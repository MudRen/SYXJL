// linji-zhuang.c ���� �ټ�ʮ��ׯ
// create bye cuer
inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yin";
}
int valid_enable(string usage)
{
	return usage == "force";
}
int valid_learn(object me)
{
        int nf,ns;
	
	nf = (int)me->query_skill("force", 1);
	
	ns = (int)me->query("guilty");                                    
	if ( me->query("gender") != "Ů��" )
		return notify_fail("��Ǵ������ʣ�������ϰ�ټ�ʮ��ׯ��\n");
        if(!undefinedp(me->query("marry")) && (int)me->query_skill("linji-zhuang",1) > 79)
                return notify_fail("�����㲻�Ǵ�Ů֮�����ܼ�����ϰ�ټ�ʮ��ׯ��\n");
        if (me->query("class")!="bonze" && (int)me->query_skill("linji-zhuang",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n");
	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����ټ�ʮ��ׯ��\n");
	
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("�ټ�ʮ��ׯֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"linji-zhuang/" + func;
}
