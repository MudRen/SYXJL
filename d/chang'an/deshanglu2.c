
// Room: /chang'an/deshanglu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "德尚路");
        set("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。东面是森森高墙，里
面关押着在本辖区内犯法的罪犯。西面是长安城的兵营，隐隐能听见里面
传来的军士们的操练声。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"jianyu",
                "south" : __DIR__"dongdajie2",
                "west"  : __DIR__"bingyingdamen",
                "north" : __DIR__"deshanglu1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}