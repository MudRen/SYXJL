// Room: /d/shaolin/donglang2.c
// By Marz 04/01/96 

inherit ROOM;


//void init();
//void close_men();
//void force_open(object);
//int do_push(string arg);
//int do_knock(string arg);
//int valid_leave(object, string);
//string look_men();


void create()
{
    set("short", "东厢走廊");
    set("long", @LONG
你走在一条走廊上，隐约可以听到东边传来呼吸声，似乎有人正在那里练
功，北边有一扇门(door)，好象是虚掩着。南边是间竹子扎就的屋子，十分的
素雅。里面飘出一阵阵的茶香，有人轻声细语地不知说那些什么，引得女孩子
＂吃吃＂笑出声来。
LONG
    );

    set("exits", ([
	"east" : __DIR__"liangongfang",
	"south" : __DIR__"chashi1",
	"west" : __DIR__"donglang1",
	"north" : __DIR__"xiuxishi2",
    ]));
                                                    
//    set("item_desc",([
//        "men"        :    (: look_men :),
//    ]));
    
    set("coor/x",-30);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-30);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-30);
	set("coor/y",90);
	set("coor/z",180);
	setup();
}
