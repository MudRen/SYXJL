// duji.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
//   if ( me->query("class") != "bonze" )
//      return notify_fail("�����ڲ���ѧϰ������\n");
    return 1;
}
