//      chanshi.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
    ������ɮ���Ų��������ĵط���
LONG
        );

        set("no_fight",1);
        set("sleep_room",1);
        set("no_steal",1);

        set("exits",([
                "southwest" : __DIR__"dating",
        ]));

        set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",50);
	set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",50);
	set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",50);
	set("coor/x",-150);
	set("coor/y",30);
	set("coor/z",50);
	setup();
        replace_program(ROOM);
}
