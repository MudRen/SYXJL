
// Room: /jingzhou/nvrenjie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "女人街");
        set("long", @LONG
这里就是名动一方的女人街了，街上来来往往的几乎都是打扮漂亮的少
妇和姑娘们，除了几个不怀好意的跨纨子弟喜欢在这里闲逛以外，很少有男
人驻足这里。靠北的是一家成装店，靠南的是一家布匹店，听说两家的老板
娘是妯娌关系呢。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nanmendajie2",
                "south" : __DIR__"nvrenjiepu4",
                "west"  : __DIR__"nvrenjie2",
                "north" : __DIR__"nvrenjiepu1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}