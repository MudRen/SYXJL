// Room: /d/wuguan/changlang1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
这是个长廊，通向东练武场，人来人往的，很是热闹。
LONG );
        set("outdoors", "wuguan");
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "west" : __DIR__"wuguandayuan",
                "east"  : __DIR__"dongwuchang",                                             
        ]));
        setup();
        replace_program(ROOM);
}
