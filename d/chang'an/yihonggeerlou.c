
// Room: /chang'an/yihonggeerlou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "怡红阁二楼");
        set("long", @LONG
你站在丽春院二楼。满耳的淫声秽响不绝如缕。两边是一间间小室，
室内布置倒也简单，但床上布置得绝对精致，突然对你产生莫名的诱惑和
冲动。几名姑娘在千娇百媚在点手儿招你，你想到她们可能就是昔日江湖
中的眼高于顶的大美女，顿时大为开心。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "down"  : __DIR__"yihongge",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}