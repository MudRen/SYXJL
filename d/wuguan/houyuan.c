// Room: /d/wuguan/houyuan.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "后院");
        set("long", @LONG
这里是后院，都是些干活做事的地方，东面过去都是柴房，西面是
一个水房。人们忙忙碌碌的进出，干着自己的活。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"shibanlu4",
                "north" : __DIR__"houyuan1",
                "east" : __DIR__"caifang", 
                "west" : __DIR__"shuifang",                                               
        ]));
        setup();
        replace_program(ROOM);
}
