//xiaolu1

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long",
	     "这里是一条上山的小路。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"northup" : __DIR__"xiaolu2",
		"southwest" : __DIR__"dongjie",
                "northeast" : __DIR__"fende",
	]));
	set("coor/x",-90);
	set("coor/y",-60);
	set("coor/z",-30);
	set("coor/x",-90);
	set("coor/y",-60);
	set("coor/z",-30);
	set("coor/x",-90);
	set("coor/y",-60);
	set("coor/z",-30);
	set("coor/x",-90);
	set("coor/y",-60);
	set("coor/z",-30);
	setup();
	replace_program(ROOM);
}
