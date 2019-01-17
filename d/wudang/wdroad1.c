// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。北边通向扬州城。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"wdroad2",
               "west" : "/d/dali/dadao1",
		"north" : "/d/city/nanmen",
                   "east" : "/d/wenrou-po/shanlu",
	]));

	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

