//      dilao.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
    ����һ����������ʪ���η���
LONG
        );

        set("exits",([
                "westup" : __DIR__"houyuan",
        ]));

        set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

