//      mishi.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
    ����һ��С���䡣
LONG
        );

        set("exits",([
                "south" : __DIR__"midao",
                "down" : "/d/city/guangchang" ,
        ]));

        set("coor/x",-170);
	set("coor/y",40);
	set("coor/z",60);
	set("coor/x",-170);
	set("coor/y",40);
	set("coor/z",60);
	set("coor/x",-170);
	set("coor/y",40);
	set("coor/z",60);
	set("coor/x",-170);
	set("coor/y",40);
	set("coor/z",60);
	setup();
        replace_program(ROOM);
}
