// Room: shandao0.c

inherit ROOM;

void create()
{
        set("short", "山道");
        set("long", @LONG
这是一条羊肠小路，弯弯曲曲的不知通往何方，路边的齐人
高的杂草密密葱葱，好象很久没人走过了，微风吹过，草丛一齐
向一个方向倒去，“沙沙”得作响！
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"liehuoqi",
  "east" : __DIR__"shandao1",
]));
        set("no_clean_up", 0);

        set("coor/x",-100);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",90);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

