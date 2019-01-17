inherit ROOM;

void create()
{
        set("short", "石道");
        set("long", @LONG
一路上日月教教众把守严密，经过两处山道，来到一处水滩之前，西面
有一道石阶通往水滩。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
		"westdown" : __DIR__"xingxingtan",
//		"east" : __DIR__"liangting",
		"south" : __DIR__"shidao",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shashou.c" : 2,
  __DIR__"npc/wang" : 1,
]));

        set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
