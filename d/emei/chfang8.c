// Room: /d/emei/chanfang8.c 峨嵋派 禅房

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long",
"这里是静照师太的禅房。简单而整齐的摆放着一张床和一张小桌，桌上\n"
"放着几本佛经，静照师太正端坐在床上，一边敲着木鱼一边念经。\n"
        );

        set("exits", ([
		"west" : __DIR__"xilang4",
               ]));   
        set("objects",([
           __DIR__"npc/jingzhao" : 1,
            ]));

        set("coor/x",-50);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",60);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}