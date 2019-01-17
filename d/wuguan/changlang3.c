// Room: /d/wuguan/changlang3.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
这是个长廊，往北通向休息室，南面是物品房，这里静悄悄的，人们
走路都也小心翼翼的，怕吵着北面休息室里休息的人。
LONG );
        set("no_fight",1);
        set("outdoors", "wuguan");        
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"wupingfang",
                "north" : __DIR__"xiuxishi",                
        ]));
        setup();
        replace_program(ROOM);
}
