
// Room: /jingzhou/jianyudamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "监狱大门");
        set("long", @LONG
你正站在荆州监狱的大门口，面对着一排高高的红墙，也许是日头大的
缘故，大门口的几个衙役显得很懒散，似乎很放心铁桶般的高墙不可能造成
犯人逃跑或越狱，不过没有谁敢擅离岗位的，因为本地知府亲自关押了一名
非常重要的犯人在里面，很多年了，当地人都似乎忘记了这件事情。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"jianyuguodao1",
                "north" : __DIR__"jingnanlu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}