//      xiaoyuan.c СԺ
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","СԺ");
        set("long",@LONG
    ���������ڵ�СԺ�������и�������
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "west" : __DIR__"guangchang",
                "north" : __DIR__"chufang",
        ]));

        set("coor/x",-150);
	set("coor/y",10);
	set("coor/z",40);
	set("coor/x",-150);
	set("coor/y",10);
	set("coor/z",40);
	set("coor/x",-150);
	set("coor/y",10);
	set("coor/z",40);
	set("coor/x",-150);
	set("coor/y",10);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}

