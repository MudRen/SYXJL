//      tulu3.c ��·
//      Designed by secret (����)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","��·");
        set("long",@LONG
    ����һ�������۵���·��������������ʥ����
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "south" : __DIR__"tulu2",
                "north" : __DIR__"shenghu",
        ]));

        set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

