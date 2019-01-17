// Room: shanpo1.c

inherit ROOM;

void create()
{
        set("short", "山坡");
        set("long", @LONG
这是通往山中小谷的一个长长的坡道，坡道由此往下越来越窄，陡
而弯曲，很是难行。

LONG
        );
        set("objects", ([ /* sizeof() == 1 */
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"banshanyao1",
  "north" : __DIR__"shanpo2",
]));
        set("no_clean_up", 0);

        set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

