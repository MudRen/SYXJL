//      tulu1.c ��·
//      Designed by secret (����)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","��·");
        set("long",@LONG
    ����һ�������۵���·��ȴ������ѩɽ������ԭ�ıؾ�֮·��
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "east" : __DIR__"caoyuan",
                "west" : __DIR__"tulu2",
        ]));

        set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

