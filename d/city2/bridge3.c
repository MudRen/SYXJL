

inherit ROOM;

void create()
{
	set("short", "桥底东侧");
	set("long", @LONG
这里是小桥西侧，一股寒风吹过，冷得你瑟瑟发抖，只想离开。
LONG
	);
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"bridge",
	]));
        set("coor/x",-40);
	set("coor/y",160);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

