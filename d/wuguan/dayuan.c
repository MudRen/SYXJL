// Room: /d/wuguan/dayuan.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "武馆大院");
        set("long", @LONG
这是个大院子，东西两边都是练武场，不少人在这里习武强身，这里
很吵，乱哄哄的，你看见不时有扛着东西的，挑着水的匆匆而过。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"",
        ]));
        setup();
        replace_program(ROOM);
}
