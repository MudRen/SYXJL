
// Room: /jingzhou/yamendatang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "衙门大堂");
        set("long", @LONG
一进来跃如你眼帘的就是大堂上高悬的“公正廉明”四个大字，堂上
有一个大案桌，后面端做着本地的知府大人凌退思大人，看起来一副鸿儒
的模样，不知道为什么，听说他在此地连任几届了，旁边放着各类的刑具。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"yamen",
                "north" : __DIR__"neizhai",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
