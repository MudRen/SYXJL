#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "归云阁");
        set("long", @LONG
这里是千佛庵的归云阁，也是峨嵋派的藏经阁，是峨嵋派的重地，阁内
按顺序摆满了书架，书架上放满了各式各样的书籍，有佛经的和武功的，峨
嵋派的弟子经过掌门同意可以来此借阅。不过要记得归还。
LONG    );

        set("exits", ([
		"westdown" : __DIR__"dcmen",
               ])); 
        set("objects",([
               __DIR__"npc/obj/jing1" : 1,
               __DIR__"npc/obj/jing2" : 1,
             ]));  
        set("coor/x",0);
	set("coor/y",40);
	set("coor/z",120);
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",120);
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",120);
	setup();
        replace_program(ROOM);
}