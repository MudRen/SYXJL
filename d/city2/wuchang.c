
inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这是一个练武场,由巨大的花岗岩石板铺就,竖立着几个木人。
LONG
	);

	set("exits", ([
		"west" : __DIR__"kang2",
	]));

	set("objects",([
                "/d/shaolin/npc/mu-ren" : 4 ]));

	set("outdoors", "city2");
	set("coor/x",-50);
	set("coor/y",200);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
