#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","小石桥");
         set("long",@long
这是一座小小的白石拱桥。桥下碧绿的湖水正荡着微波。远处的湖面上
传来阵阵歌声，不远处两只鸳鸯在一起戏水，岸边的柳树随着湖面上吹
来的微风时不时地摇摆着。
long);
// will add a npc to ask chuan
          set("outdoors","mr");
          set("exits", ([
           "south" : __DIR__"testmatou1",
             "northwest" : __DIR__"hubian1",
]));
          replace_program(ROOM);
          set("coor/x",100);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
