
// Room: /jingzhou/chaguan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "茶馆");
        set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，忍不住也想坐下来休闲一下。
几张八仙桌一字排开，坐满了客人，正听着台上说书先生口沫横飞地讲着刘
备借荆州的古老传说，不知道重复地讲了多少年了。你要想打听江湖掌故和
谣言，这里是个好所在。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"yingdulu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}