// nroad7.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你走在一山路上，四周有一座座小山丘。
LONG );
        set("exits",([
                "eastdown" : "/d/xueshan/shanjiao",
                "south"    : __DIR__"nroad6",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/shanyong" : 1,
        ]));
        set("outdoors", "xueshan");
        set("coor/x",-130);
	set("coor/y",40);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",40);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",40);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",40);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

