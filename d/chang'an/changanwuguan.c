// Room: /d/chang'an/jiangjunfu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "将军府");
	set("long", 
"这里就是鼎鼎大名的长安武馆了，只见门楼高挑，上面着意用烫金大
楷写着四个大字:"HIY"
　　　　　            长  安  武  馆
"NOR"
    门口站着一位满脸横肉的大汉接待着前来学武学艺的学徒，原来他就
是来自荆州府的浪翻云。\n"
 );
//        set("outdoors", "chang'an");
	set("exits", ([
		"south" : __DIR__"chongwujie",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/junshi" : 2,
	]));
	setup();
	replace_program(ROOM);
}

