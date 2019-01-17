// by mayue


inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这里是个花园，一年四季都生长着各种奇异的花草，在阳光下发出七彩
妖艳的光辉。花园里一片沉寂，竟看不到一只蜜蜂或蝴蝶飞舞。有一条石子
小路通向前面一座花厅。
LONG
	);
        set("outdoors", "honghua");

	set("exits", ([
                "west" : __DIR__"huating4",
                "south" : __DIR__"huayuan5",
                "east" : __DIR__"zoulang",
                "north" : __DIR__"huayuan6",
	]));
        set("objects", ([
                "/d/honghua/dizi" : 4,
	]));
    

	setup();
	replace_program(ROOM);
}

