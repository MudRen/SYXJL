
// Room: /jingzhou/tading.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "塔顶");
        set("long", @LONG
从小窗望下去，南面是气势磅礴的长江，江上有各类的船只竟相逐流。
脚下是一片葱郁的竹林，确实是个好地方。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "down"  : __DIR__"wanshoubaota",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}