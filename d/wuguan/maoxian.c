// Room: /d/wuguan/maoxian.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "冒险基础");
        set("long", @LONG
在这里，你能学到一些冒险的基本指令，例如：闯荡、逃生、解
谜等等。以及能学到一些日常生活的指令。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"baishi",
        ]));
        set("objects", ([
                __DIR__"npc/orange" : 1,
        ]));
            
        setup();
        replace_program(ROOM);
}
