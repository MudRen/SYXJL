
// Room: /jingzhou/neizhai.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "内宅");
        set("long", @LONG
这里是衙门的内宅，住着林知府的家眷。外人到此就该止步了。往前
走是一座精致的小阁楼。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"yamendatang",
         ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}