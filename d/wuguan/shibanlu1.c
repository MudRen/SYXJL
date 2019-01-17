// Room: /d/wuguan/shibanlu1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
你走在一条石板路上，北面过去就是后院了，南面是西练功场，
西面传来阵阵饭菜的香气，那里是武馆的饭厅。东面过去是武馆大厅。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"",
        ]));
        setup();
        replace_program(ROOM);
}
