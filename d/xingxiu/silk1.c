// /d/xingxiu/silk1.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是一条中原和西域之间的商道。东边有一座雄伟的关隘，西面则通往西域。
LONG
        );
        set("outdoors", "关外");

        set("exits", ([
                "east" : __DIR__"jiayuguan",
		"west" : __DIR__"silk2",
                "south":"/d/xiangyang/caodi3",
        ]));

        set("coor/x",-70);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-70);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-70);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-70);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

