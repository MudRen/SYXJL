// shihunxing.c 蚀魂星
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("蚀魂星", ({ "shihun xing", "xing" }) );
	set("long", 
		"这是一粒暗红色的小弹丸，看起来并不起眼，似乎是由硫磺硝磷之类制成的火弹。\n" );
	set_weight(15);
	set("unit", "粒");
	set("value", 30000);

	setup();
}