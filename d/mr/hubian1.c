#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","湖边");
         set("long", @LONG
俗话说 : 上有天堂, 下有苏杭。这里正是大大有名的太湖。 湖面绿波上漂
着一叶叶的小舟, 一阵阵悦耳的小曲儿随着湖上的轻风不时漂入你的耳中。
LONG
      );
       set("outdoors","mr");
       set("exits", ([
           "west" : __DIR__"hubian",
	   "southeast" : __DIR__"shiqiao",
]));
       set("coor/x",90);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",20);
	set("coor/z",0);
	setup();
       replace_program(ROOM);
}
