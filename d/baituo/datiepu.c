//datiepu.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
             "������һ�Ҵ����̣�����æ�Ŵ������Ʊ����������������͡�\n"
        );
        set("exits", ([
                "north" : __DIR__"dongjie",
        ]));
	set("objects",([
		__DIR__"npc/smith" : 1,
	]));
        set("coor/x",-100);
	set("coor/y",-80);
	set("coor/z",-30);
	set("coor/x",-100);
	set("coor/y",-80);
	set("coor/z",-30);
	set("coor/x",-100);
	set("coor/y",-80);
	set("coor/z",-30);
	set("coor/x",-100);
	set("coor/y",-80);
	set("coor/z",-30);
	setup();
        replace_program(ROOM);
}





