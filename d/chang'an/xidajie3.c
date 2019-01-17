
// Room: /chang'an/xidajie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西边是一个很大的十
字街口。东面是长安的中心钟楼。南面是一家专门经营玉器的店铺，看起
来古朴典雅。北面是将军府邸。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"zhonglou",
                "south" : __DIR__"yuqihang",
                "west"  : __DIR__"xidajie2",
                "north" : __DIR__"jiangjunfu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}