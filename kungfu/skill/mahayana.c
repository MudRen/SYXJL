// mahayana.c ������͹�
//create bye cuer
inherit SKILL;
void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int valid_learn(object me) 
{       
        int ji = (int)me->query_skill("mahayana",1); 
        if (me->query("class")!="bonze" && ji > 99 )
                return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n");
        if( ji > 9 && me->query("shen") < (int)(ji*ji*ji/4) && me->query("shen") < 500000 )
                return notify_fail("������в������޷���������͵ľ������ۡ�\n");
        return 1;
}
int practice_skill(object me)
{       
        return notify_fail("������͹�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
