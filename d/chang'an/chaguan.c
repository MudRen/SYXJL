
// Room: /chang'an/chaguan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "茶馆");
        set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌
一字排开，坐满了客人，或高声谈论戏院新来花旦的唱腔，或低头商议着
一些生意上的事。院子里有一口水井(jing)。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"beidajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}