#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","小石桥");
         set("long",@long
这是一座小小的白石拱桥。桥下碧绿的湖水正荡着微波。石桥的东面是
一条鹅卵石铺成的小径，西面是曼佗罗山庄的前院。
long);
set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaojing5",
             "west" : __DIR__"qianyuan",
]));
        set("coor/x",100);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
