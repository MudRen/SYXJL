// mudao.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("ľ��", ({ "mudao", "dao", "blade" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "iron");
		set("long", "����һ��ľ�ƵĶ̵����������ô˵����������ˡ�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
		
	}
	init_blade(5);
	setup();
}
