//      mishi.c 密室
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","密室");
        set("long",@LONG
    这是一条小房间。
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
