// by mayue

inherit ROOM;

void create()
{
        set("short", "飞龙亭");
	set("long", @LONG
这里是一个花园中的小亭子，雕梁画栋，古色古香。亭子当中立着几个铜人。
LONG
	);
//       set("outdoors", "honghua");

	set("exits", ([
		"west" : __DIR__"huayuan2",
		"north" : __DIR__"huating1",
	]));
        set("objects", ([
                "/clone/npc/tong-ren":4,
	]));
    

	setup();
	replace_program(ROOM);
}

