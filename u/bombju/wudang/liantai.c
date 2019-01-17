// Room: /d/shaolin/donglang2.c
// By Marz 04/01/96 

inherit ROOM;


//void init();
//int close_men();
//int force_open(object);
//int do_push(string arg);
//int do_knock(string arg);
//int valid_leave(object, string);
//string look_men();


void create()
{
    set("short", "十二莲台");
    set("long", @LONG
你走在一条宽敞的石廊上，南边是一个高高的牌楼，雕梁画栋很是好看。东
边有一扇门(door)，好象是虚掩着。西边是间竹子扎就的屋子，十分的素雅，里
面飘出一阵阵的茶香，有人轻声细语地不知说那些什么，引得女孩子＂吃吃＂笑
出声来。
LONG
    );

    set("exits", ([
	"north" : __DIR__"zijincheng",
	"south" : __DIR__"santian",
	"west" : __DIR__"chashi2",
	"east" : __DIR__"xiuxishi1",
    ]));
                                                    
//    set("item_desc",([
//        "men"        :    (: look_men :),
//    ]));
    
    set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",230);
	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",230);
	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",230);
	setup();
}
