
// Room: /jingzhou/nvrenjie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "女人街");
        set("long", @LONG
这里是女人街最为热闹的路段了，到不是因为北面的珠宝店生意好，
反到是它对面的一家饮食店因为各类可口的小食店生意非常兴隆，几乎所
有到这里逛街的人都要到那里去尝尝小吃，喝点饮料。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nvrenjie2",
                "south" : __DIR__"xiaochidian",
                "west"  : __DIR__"huadian",
                "north" : __DIR__"nvrenjiepu5",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}