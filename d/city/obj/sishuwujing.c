inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIR "�����徭" NOR, ({  "book","shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������徭���Ƕ���ʶ�֣�Ӧ�ԿƾٵĽ̲ġ�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",	
			"exp_required":	10,	// minimum combat experience required
			"jing_cost": 5, 	// jing cost every time study this
			"difficulty":	22,	// the base int to learn this skill
			"max_skill":	80,	// the maximum level you can learn
		]) );
	}
}
