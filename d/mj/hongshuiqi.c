// Room: hongshuiqi.c

inherit ROOM;

void create()
{
        set("short", "洪水旗");
        set("long", @LONG
这里是明教的洪水旗，旗中教众个个精通水性，且有旗使唐洋所
创的毒水阵，令敌人闻风丧胆，屡建奇功。向东就是由洪水旗守护的
明教圣地之一碧水寒潭。由南往下有条弯弯的小路通向一个山谷。

LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/tangyang" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"shanlu3",
  "north" : __DIR__"liehuoqi",
  "west" : __DIR__"lianwu-chang1",
  "east" : __DIR__"shanya",
]));
        set("no_clean_up", 0);

        set("coor/x",-110);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

