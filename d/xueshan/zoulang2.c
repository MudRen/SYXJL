//      zoulang2.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
    ������ѩɽ���ڵ����ȡ�
LONG
        );

        set("exits",([
                "down" : __DIR__"cedian2",
                "east" : __DIR__"dating",
                "eastup" : __DIR__"zoulang3",
        ]));

        set("coor/x",-170);
	set("coor/y",20);
	set("coor/z",50);
	set("coor/x",-170);
	set("coor/y",20);
	set("coor/z",50);
	set("coor/x",-170);
	set("coor/y",20);
	set("coor/z",50);
	set("coor/x",-170);
	set("coor/y",20);
	set("coor/z",50);
	setup();
        replace_program(ROOM);
}

