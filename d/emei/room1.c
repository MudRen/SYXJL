#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "寝室");
        set("long",
"这里是峨嵋弟子们休息的地方。环顾室内，这里昏暗而又安静，几个\n"
"峨嵋弟子睡得正香，也许是由于都是女孩的缘故室内东西不多但很整洁。\n"
        );                     

        set("exits", ([
		"south" : __DIR__"huayuan1",
               ]));  
        set("sleep_room",1); 
        set("no_fight",1);
        set("coor/x",-50);
	set("coor/y",90);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",90);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",90);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}