
// Room: /jingzhou/jiulouerlou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "酒楼二楼");
        set("long", @LONG
这里是雅座，环境和服务都要好得多，自然价格相对也要贵一些，所以
经常上来的都是些富豪人家，这里边吃喝边作交易。不过偶尔有些文人学士
也经常在这里吟诗作画。这里也是城里举办喜宴的最佳场所。东面是一池湖
水，碧波荡漾。北面过了城墙便是一眼望不到头的田野。墙上挂着价格牌子。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "down"  : __DIR__"jiulou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}