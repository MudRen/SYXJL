//      shanmen.c 雪山寺山门
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","雪山寺山门");
        set("long",@LONG
    这里就是著名的雪山寺。寺庙依山而建，显得格外壮观。
方圆数百里内的香客都来此朝拜。
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "north" : __DIR__"guangchang",
                "southdown" : __DIR__"shanlu2",
        ]));
        set("objects", ([
                __DIR__"npc/saxi" : 1, 
   ]));
        set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",40);
	set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",40);
	set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",40);
	set("coor/x",-160);
	set("coor/y",0);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
