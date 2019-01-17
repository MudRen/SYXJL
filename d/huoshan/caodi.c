
// Room: /huoshan/caodi.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "草地");
        set("long", @LONG
又是一片绿油油的草地，踩在上面感觉真是很舒服。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"yongdao4",
                "south" : __DIR__"huajing1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}