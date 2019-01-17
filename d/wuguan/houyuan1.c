// Room: /d/wuguan/houyuan1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "后院");
        set("long", @LONG
这里是后院，都是些干活做事的地方，东面过去都是木柴房，西面
是一个马房。人们忙忙碌碌的进出，干着自己的活。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"houyuan",
                "north" : __DIR__"houyuan2",
                "east" : __DIR__"mufang", 
                "west" : __DIR__"mafang",                                               
        ]));
        setup();
        replace_program(ROOM);
}
