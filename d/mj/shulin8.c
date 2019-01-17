// Room: shulin8.c

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这是一片偌大的树林，古木参天，遮云蔽日。你进来就迷失了方向，
不知道现在自己身在何处。林中不时传来野兽怪异的低吼和啸叫,令你不
禁毛骨悚然，只想早点离开。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shulin7",
  "west" : __DIR__"shulin9",
  "south" : __DIR__"shulin10",
  "east" : __DIR__"shulin",
]));
        set("no_clean_up", 0);

        set("coor/x",-170);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-170);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-170);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-170);
	set("coor/y",90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

