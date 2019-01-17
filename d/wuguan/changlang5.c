// Room: /d/wuguan/changlang5.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
这是个长廊，通向西练武场，人们急冲冲的走过，不时有人被抬出来，
看样子是练功脱力昏倒的。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "east" : __DIR__"wuguandayuan",
                "west" : __DIR__"xiwuchang",                
        ]));
        setup();
        replace_program(ROOM);
}
