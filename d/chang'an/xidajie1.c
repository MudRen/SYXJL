
// Room: /chang'an/xidajie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。西面是玉祥内门，东边
是一个大十字街口，只见人来人往，络绎不绝。北面是一加打铁铺。里面
不时传来“丁丁冬冬”的铁器敲击声。南面是一家木工房。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"xidajie2",
                "south" : __DIR__"mugongfang",
                "west"  : __DIR__"westgate1",
                "north" : __DIR__"tiejiangpu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}