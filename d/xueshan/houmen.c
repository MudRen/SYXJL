//      houmen.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
    ����ѩɽ�µĺ��š�
LONG
        );

        set("exits",([
                "south" : __DIR__"houyuan",
        ]));

        set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",40);
	set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",40);
	set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",40);
	set("coor/x",-170);
	set("coor/y",30);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}



