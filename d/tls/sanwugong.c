inherit ROOM;

void create()
{
        set("short", "三无宫");
        set("long",@LONG
这里可以买香到后面参拜西方大士。几个进香客正围着一个老年僧
人讨价还价。北面是犯戒的僧人面壁的地方，向西就是天龙寺的重地了。
LONG
        );
        set("exits", ([
                "east" : __DIR__"doumugong",
                "west" : __DIR__"jialan",
        	"north" : __DIR__"mianbishi",
	]));
	set("objects",([
                __DIR__"npc/guest" : 4,
		__DIR__"npc/laoniansengren" : 1,
                __DIR__"npc/gui-bao" : 1,
        ]));
        set("coor/x",-60);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-60);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
