
// Room: /jingzhou/sanyijie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "三义街");
        set("long", @LONG
这条街看起来路面整齐，西面是本地最具规模的妓院，里面不时地传
出一阵阵浪荡的笑声。东面是一家杂货铺，在里面购物的人看来不少。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"zahuopu",
                "south" : __DIR__"huatai",
                "west"  : __DIR__"jiyuan",
                "north" : __DIR__"sanyijie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}