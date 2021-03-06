
// Room: /jingzhou/wanjiadazhai.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "万家大宅");
        set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大
门两侧，朱漆大门足足有三寸厚。门上挂着两个灯笼，写着“万”字。万
家是当地首富，而且在江湖中名头也不小，人称“五云手”。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"quyuanlu",
                "west"  : __DIR__"wanjiadayuan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
