// box.c   ����

#include <ansi.h>

inherit ITEM;

void create()
{
          set_name(HIY"����"NOR,({ "personal computer", "computer"}) );
	set_weight(3000);
	set_max_encumbrance(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "̨");
              set("long","һ̨ 286���ĵ��ԣ����Ǳı�ƽ��ʹ�õĶ�����\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

void init()
{
           add_action("do_off","off");
           add_action("do_on","on");
}

