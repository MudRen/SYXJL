// wdroad4.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，四周静悄悄的。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : "/d/xiaoyao/shulin3",
		"south" : __DIR__"wdroad5",
		"north" : __DIR__"wdroad3",
	]));

	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

