//      hubian3.c ����С·
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����С·");
        set("long",@LONG
    ����ʥ���ߵ�С·��
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "north" : __DIR__"hubian4",
                "southwest" : __DIR__"hubian2",
        ]));

        set("coor/x",-100);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
