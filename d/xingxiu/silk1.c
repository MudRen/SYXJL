// /d/xingxiu/silk1.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
����һ����ԭ������֮����̵���������һ����ΰ�Ĺذ���������ͨ������
LONG
        );
        set("outdoors", "����");

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

