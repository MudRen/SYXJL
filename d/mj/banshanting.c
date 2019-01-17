// Room: banshanting.c

inherit ROOM;

void create()
{
        set("short", "半山厅");
        set("long", @LONG
上到岭上，岭上有个小厅，建筑清丽，真令人感叹其建筑
材料是怎麽运上山来的。放眼望去，只见迎面飞来一道白链，
如万丈银河，泻入深谷，若似静止一般，不闻其声。此刻情景
如图画里万壑千谷，壁上一道飞瀑，云烟处茅舍几间，小桥一
抹，诗情画意。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"shanlu1",
  "north" : __DIR__"banshanyao1",
]));
        set("no_clean_up", 0);

        set("coor/x",-100);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

