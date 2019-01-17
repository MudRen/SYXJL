// Room: /d/wuguan/baishi.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "拜师学艺");
        set("long", @LONG
本ＭＵＤ中，有数个门派：有正有邪，也有亦正亦邪的。想在武
林上成为高手，就要选一门派，投其门下，学其武功，方能成为一代
高手。但是，如果你不想拜任何一个门派也可，武林中流传着数武功
绝学，供玩家寻找，但要无师自通，却是很困难的。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"baishi1",
        ]));
        set("objects", ([
                __DIR__"npc/lxq" : 1,
        ]));
                
        setup();
        replace_program(ROOM);
}
