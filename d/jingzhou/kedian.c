
// Room: /jingzhou/kedian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "客店");
        set("long", @LONG
这是一家廉价的小客栈，由于荆州是重要的交通枢纽，所以生意非常
兴隆。外地游客多选择这里落脚。店小二里里外外忙得团团转，接待着操
着南腔北调的江湖豪客和生意人。门口立着一块着一个牌子(paizi)。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"sanyijie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}