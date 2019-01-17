
// Room: /chang'an/caizhudamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "财主大门");
        set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大
门两侧，朱漆大门足足有三寸厚。门上挂着两个灯笼，写着“高”字。高
家是当地首富，而且以蛮横著称。几条狼狗嚎叫着向你冲了过来。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"caizhudayuan",
                "east"  : __DIR__"shajinqiao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}