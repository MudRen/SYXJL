// Room: /d/wuguan/changlang4.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
这是个长廊，通向馆主的卧室，这里静悄悄的，没有什么人来，
走廊两边爬满了爬山虎，外面烈日，可是你走在走廊里只觉得一阵
清凉。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"wuguandating",
                "north" : __DIR__"woshi",                
                "east" : __DIR__"shufang",                
        ]));
        setup();
        replace_program(ROOM);
}
