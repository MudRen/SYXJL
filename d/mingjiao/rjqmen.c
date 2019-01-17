//RJQMEN.C

inherit ROOM;

void create()
{
	set("short", "侧门");
	set("long", @LONG
这是锐金旗的一个侧门，大概只容得下一个人进出，每个教众
到此，都必须出示一张腰牌，才可进入。
LONG
	);

	set("exits", ([
		"enter" : __DIR__"rjqyuan",
		"east" : __DIR__"torjq3",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-130);
	set("coor/y",-10);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}