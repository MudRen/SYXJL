#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long",
"这里是静虚师太的禅房。简单而整齐的摆放着一张床，一边敲着木鱼一边念经。\n"
"放着几本佛经，静虚师太正端坐在床上，一边敲着木鱼一边念经。\n"
       );

        set("exits", ([
		"east" : __DIR__"xilang3",
               ]));  
        set("objects", ([
          __DIR__"npc/jingxu" : 1,
             ]));
        set("coor/x",-70);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",50);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}