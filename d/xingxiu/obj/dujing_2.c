// dujing_2.c �����޶������²᡽��

inherit ITEM;

void create()
{
	set_name("�����޶������²᡽��", ({ "du jing", "jing" }) );
	set_weight(100);
	set("unit", "��");
        set("long",
"\n                 �����޶������²᡽��\n\n"
"��������Ϊ���ޱ��䣬���Դ˾������������书й©�����ˣ�����Ϊ��ʦ���桢\n"
"����ʦ�š�����ʦ֮ͽ����������أ�����ӱ�����֮�����˳��б����ߣ���\n"
"���Ӽ�һ��ɱһ������ʮ��ɱʮ�����ϲ���˽�ı��ű����߹���������\n\n"
"�����������������������������������������������������������ɡ�������\n"
"\n"	);
	set("value", 700);
	set("material", "paper");
	set("skill", ([
		"name": "poison",  //name of the skill
		"exp_required": 0 , //minimum combat experience required
		"jing_cost": 10+random(1),// jing cost every time study this
		"difficulty":	20,	// the base int to learn this skill
		"max_skill":	31	// the maximum level you can learn
	]));
}
