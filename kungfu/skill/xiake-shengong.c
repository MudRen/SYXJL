//xiake-shengong   ������--���͵��ϳ��ڹ� 
// dts@xkx, cleansword@xkx

inherit FORCE;

string *jingmai=({
  "����",
  "����",
  "����",
  "����",
  "��ά",
  "��ά",
  "����",
  "����",
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
  return notify_fail("����������̫�������̫С��ǿ����ϰ���߻���ħ�ġ�\n");

        if ( nb < 100 && nb <= nh )
return notify_fail("�������Ǵӡ������С�����������ģ�����ѧ������̫�ͣ����޷������������书��\n");

if ( nf < nh)
return notify_fail("�������Ի����ڹ�Ϊ����������ڹ���򲻹�������Ҫ��������n");

        if ( ns < (nh*100) ) 
return notify_fail("������׷��һ�����ߵ��⾳���������֮�����������޷���������⾳��\n");

        if( (nh <=80)&&(me->query("jingmai")<(nh/10)))
return notify_fail("������ÿһ�㶼�Դ�ͨ�����ϵ��澭����Ϊ���������"+
   jingmai[nh/10-1]+"����û��ͨ���޷�������ϰ��\n");   
        return 1;
}


int practice_skill(object me)
{
        if( (int)me->query("max_neili") < 500)
         return notify_fail("��ý�һ��������������\n");
        if( (int)me->query("qi") < 30 )
                return notify_fail("�����������\n");
        if( (int)me->query("neili") < 10 )
                return notify_fail("�������������\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;

}

string exert_function_file(string func)
{
        return __DIR__"xiake-shengong/" + func;
}