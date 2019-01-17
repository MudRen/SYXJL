// Room: /d/wuguan/wupingfang.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "物品房");
        set("long", @LONG
这是物品房，一个大架子。上面放的整整齐齐，看来这里的管家是
很认真负责的，一些人正在跟管物品工具的管家说着什么。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"changlang2",
                "north" : __DIR__"changlang3",             
                "west" : __DIR__"shibanlu",                
        ]));
      	set("objects", ([
                __DIR__"npc/laoli" : 1,
        ]));        
        setup();
        replace_program(ROOM);
}
