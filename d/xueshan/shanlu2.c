//      shanlu2.c ɽ·
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","ɽ·");
        set("long",@LONG
    ����һ����ɽ��С·��
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "northup" : __DIR__"shanmen",
                "eastdown" : __DIR__"shanlu1",
        ]));

        set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",-10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
