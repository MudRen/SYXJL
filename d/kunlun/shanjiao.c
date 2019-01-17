// Room: /d/kunlun/shanjiao.c

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "昆仑山下");
    set("long", @LONG
这里是千里昆仑的东麓，远望苍天浩浩，白云悠悠。东方沃野千里，
楚天辽阔；西面高山巍巍，迤逦万里。叱咤武林的昆仑派就座落在这群
山之中。昆仑----是多少武林豪杰所向往的地方，在那里，有无数生死
相许的好兄弟，无论是正是邪。就在这西方的群山之后，等待着你去谱
写又一曲武林传奇。
LONG
    );

    set("exits", ([
	"west" : "/d/kunlun/shanlu",
        "east" : "/d/xingxiu/shanjiao",
      
    ]));

    set("outdoors", "mingjiao");
    set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

