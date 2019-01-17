// nroad6.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你走在一山路上，四周有一座座小山丘。远处可以看见终年积雪
的山尖。周围的树草已经很难看得到了。
LONG );
        set("exits",([
                "north"   : __DIR__"nroad7",
                "southup" : __DIR__"nroad5",
        ]));
        set("objects",([
                __DIR__"npc/huatiegan" : 1,
        ]));
//	set("no_clean_up", 0);
        set("outdoors", "xueshan");
        set("coor/x",-130);
	set("coor/y",30);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",30);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",30);
	set("coor/z",-10);
	set("coor/x",-130);
	set("coor/y",30);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

