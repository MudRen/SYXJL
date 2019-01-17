// Room: jumuqi.c

inherit ROOM;

void create()
{
        set("short", "巨木旗");
        set("long", @LONG
这里是明教的巨木旗，墙边的一个木架上放满了砍伐工具，中间
堆放着刚砍下来的木材，数十个教众忙着将木材整理加工，由于明教
日渐壮大，巨木旗肩负起了不断扩建这个宏大建筑的重任。西面是一
片遮云蔽日的树林。东面是练武场。

LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wencangsong" : 1,
]));
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"ruijinqi",
  "west" : __DIR__"shulin",
  "east" : __DIR__"lianwu-chang3",
]));
        set("no_clean_up", 0);

        set("coor/x",-150);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-150);
	set("coor/y",80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

