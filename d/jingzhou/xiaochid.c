
// Room: /jingzhou/xiaochidian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "小吃店");
        set("long", @LONG
看来这店铺的老板十分精明，在这里开了一家专卖小食品的门面，确实
招来了很多生意，包括那些其实不喜欢陪老婆逛街的男人都借口躲在这里休
息，女孩子也喜欢逛累了就跑到这里喝点她们喜欢的饮料。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"nvrenjie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}