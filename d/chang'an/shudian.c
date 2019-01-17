
// Room: /chang'an/shudian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "书店");
        set("long", @LONG
这是一家很小的书屋，你在这里也许能买到一些对你有用的书籍。北
面的墙上挂着一副孔老夫子的画像，下面端坐着一名正在孜孜不倦地读书
的老学究，看来他开这家书店也只是为了糊口而已。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"nandajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}