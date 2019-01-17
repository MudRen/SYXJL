#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","小径");
         set("long",@long
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木
点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，往西面去是这条
小径的延伸。
long);
         set("ourdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaoshe",
             "west" : __DIR__"xiaojing2",
]));
        set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
