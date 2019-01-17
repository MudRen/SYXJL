// Room: /chang'an/kaochang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "考场");
        set("long", @LONG
你走进考场，大门口立着一块“肃静”的牌子。一名看起来比较和蔼
的衙役示意你在这里不要喧哗。一名监考官做在考场正上方的一张椅子上，
上上下下打量了你一番。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"shajinqiao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}