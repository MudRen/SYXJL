// baishulin1.c 柏树林
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "柏树林");
        set("long", @LONG
绕过翠屏谷的山壁，眼前是一片大柏树林，想是由于山壁挡住了视线，
在山下的山路上根本想不到这里的柏树竟会有这么密这么高。你踏进柏树
林中，阳光全被头顶的树叶遮住了，越往树林深处，光线越是幽暗。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"cuipinggu",
                "northup" : __DIR__"baishulin3",
                "east" : __DIR__"baishulin2",
        ]));
        set("no_clean_up", 0);
        set("coor/x",-100);
	set("coor/y",170);
	set("coor/z",30);
	set("coor/x",-100);
	set("coor/y",170);
	set("coor/z",30);
	set("coor/x",-100);
	set("coor/y",170);
	set("coor/z",30);
	set("coor/x",-100);
	set("coor/y",170);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

