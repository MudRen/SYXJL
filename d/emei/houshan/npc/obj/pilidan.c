// pilidan.c ������

inherit ITEM;

void create()
{
	set_name("������", ({"pili dan", "dan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����µ������ޱȵ���������\n");
		set("unit", "��");
		set("value", 100);
	}
}
