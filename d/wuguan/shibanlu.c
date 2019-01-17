// Room: /d/wuguan/shibanlu.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
你走在一条石板路上，从这里往东是物品房，你看见有不少人
手里拿着各样的工具，从那边过来，西面是武馆大厅。
LONG );
        set("outdoors", "wuguan");
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"zhangfang",
                "east" : __DIR__"wupingfang",                
                "west" : __DIR__"wuguandating",                
                "north" : __DIR__"xuetang",                
        ]));
        setup();
        replace_program(ROOM);
}
