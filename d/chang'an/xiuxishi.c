// Room: /chang'an/xiuxishi.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "休息室");
        set("long", @LONG
你一进来就感觉这里凌乱得很，被子也没人叠，胡乱地扔在床上，你
做工累了可以在这里休息一下。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"xunbufang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}