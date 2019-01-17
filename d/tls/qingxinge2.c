inherit ROOM;

void create()
{
        set("short", "清心阁二楼");
        set("long",@LONG
这是寺中诸僧前去后院参修之前清心净欲的地方。阁中只有地面放有
几个蒲团，除此之外别无它物，确然是个清静之处。
LONG
        );
        set("exits", ([
		"down": __DIR__"qingxinge",
            ]));
	set("sleep_room", 1);
        set("no_fight",1);
        set("no_steal",1);
        set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",40);
	set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",40);
	set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",40);
	set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
