// hudi2.c 湖底

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "湖底");
	set("long", @LONG
这里是小湖湖底，四周黑忽忽的，头顶上只能看见一点亮光，身边的水流
似乎更加湍急了。脚下似乎有一点亮光，也不知是些什么。周围一片死寂，似
乎暗藏着层层杀机。
LONG
	);
        
	set("exits", ([
		"down" : __DIR__"hudi3",
        ]));
	setup();
	replace_program(ROOM);
}
