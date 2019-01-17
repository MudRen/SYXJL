//xiaolu2

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long",
	     "这里是一条上山的小路。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"northup" : __DIR__"xiaolu3",
		"southdown" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/man" : 1,
	]));

	set("coor/x",-90);
	set("coor/y",-50);
	set("coor/z",-20);
	set("coor/x",-90);
	set("coor/y",-50);
	set("coor/z",-20);
	set("coor/x",-90);
	set("coor/y",-50);
	set("coor/z",-20);
	set("coor/x",-90);
	set("coor/y",-50);
	set("coor/z",-20);
	setup();
	replace_program(ROOM);
}
