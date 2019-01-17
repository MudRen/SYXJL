// wdroad8.c 黄土路
// by Xiang

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
	你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。西边是一座高山。
LONG
	);
        set("outdoors", "武当");

	set("exits", ([
                "north" : "/d/xiangyang/caodi6",
		"west" : __DIR__"shanmen",
		"southwest": "/d/emei/shijie10",
                "east": "/d/wudang/wdroad7",
	]));
	set("objects", ([
		__DIR__"npc/yetu" : 4 ]));

	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

