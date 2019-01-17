
// Room: /jingzhou/nvrenjie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "女人街");
        set("long", @LONG
虽然只是专卖女性用品的地方，但人流程度绝不会比其他商业区少到那
里去，看来女人还是消费者的主流，北边是一家专买针线的店铺，南边是一
家胭脂花粉店。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nvrenjie1",
                "south" : __DIR__"nvrenjiepu2",
                "west"  : __DIR__"nvrenjie3",
                "north" : __DIR__"nvrenjiepu3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}