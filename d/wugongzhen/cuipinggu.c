// cuipinggu.c 翠屏谷
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "翠屏谷");
        set("long", @LONG
你的面前是一座形如屏风的大山壁，山壁上郁郁葱葱都是树，一眼看
过去，全是一片翠绿色。这就是此地名叫翠屏谷的由来。从这里继续
北上，就到了终南山上的柏树林了。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"shanlu3",
                "northup" : __DIR__"baishulin1",
        ]));
        set("no_clean_up", 0);
        set("coor/x",-100);
	set("coor/y",160);
	set("coor/z",20);
	set("coor/x",-100);
	set("coor/y",160);
	set("coor/z",20);
	set("coor/x",-100);
	set("coor/y",160);
	set("coor/z",20);
	set("coor/x",-100);
	set("coor/y",160);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}

