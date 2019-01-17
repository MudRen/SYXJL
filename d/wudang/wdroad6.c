// wdroad6.c 黄土路
// by Xiang

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
	你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里是湖北境界，
据说经常有土匪出没，不可久留。再往西走，就是戒备深严的襄阳城了。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northeast" : __DIR__"wdroad5",
                "west" : "/d/xiangyang/eastgate2",
	]));

	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

