// renshen.c �˲�

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("�˲�", ({"renshen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ó��ε���ɽ�Ρ�\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{                              
   int neili;
   object me = this_player();
	if (!arg || (arg != "renshen" && arg != "shen" ) )
		return notify_fail("��Ҫ��ʲô��\n");
         neili=me->query("max_neili");
         neili = neili + 5;
         me->set("max_neili",neili);
         message_vision("$N����һ���˲Σ��е������������ӣ�\n", me);
         destruct(this_object());
         return 1;

}

