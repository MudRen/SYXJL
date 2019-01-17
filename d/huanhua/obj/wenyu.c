// TIE@FY3

#include <weapon.h>

#include <ansi.h>

inherit HAMMER;

void create()

{

	set_name(HIG  "千年温玉" NOR, ({ "wen yu" }) );

	set_weight(1000);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("unit", "块");

		set("long", "一块醉人的玉石，绿得醉人呀．．．

上书一行小字：你可以用它来ｃｕｒｅ. . .\n");

		set("max_cure",10);

		set("material", "stone");

	}

	init_hammer(10);

	setup();

}

void init()

{

	if(environment()==this_player())

	add_action("do_cure","cure");



}



int do_cure()

{

	object me;

	me = this_player();

	if(query("max_cure") <=0)

	return notify_fail("此温玉的疗效已经被用光了！\n");

	if(me->query("eff_qi") == me->query("max_qi"))

	return notify_fail("此温玉只能用来治疗外伤，对内伤没用！\n");

	me->set("eff_qi",(int)me->query("max_qi"));

	add("max_cure",-1);

	message_vision("$N将一块千年温玉放在伤口上轻轻揉动，血淋淋的伤口

居然奇迹般的愈合了！！\n",me);

	return 1;

}

