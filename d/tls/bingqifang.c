// bingqifang.c


inherit ROOM;

void create()
{
        set("short", "兵器室");
        set("long", @LONG
这里是天龙寺的兵器室，靠墙是一排长长的兵器架，上面插满了长剑。
几个光着上身的和尚还在那不停的打造长剑，忙个不停。
LONG
        );
        set("exits", ([
                "west" : __DIR__"yuhuayuan",
]));
        set("no_clean_up", 0);
        set("objects", ([
                       __DIR__"obj/muyuchui": 1,
                       __DIR__"obj/changjian": 1,
]));
        set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
