// Room: /d/wuguan/houyuan1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "后院");
        set("long", @LONG
这里是后院外了，四周都是菜地，往北是个小山坡，东西面都是
用篱笆围起的菜地，种着各样的菜，篱笆很破烂，摇摇欲坠，看来这
里没什么人打理。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"houyuan1",
                "east" : __DIR__"caidi",
                "west" : __DIR__"caidi1",                                                
        ]));
        setup();
        replace_program(ROOM);
}
