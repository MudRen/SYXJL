
// Room: /jingzhou/nvrenjiepu1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "女人街店铺");
        set("long", @LONG
这是一家专门经营大家闺秀用品的经销店，店主是名少妇，身段娇好，
打扮十分得体。衣架上挂着各类漂亮的衣服，有着不同的型号。看来老板娘
对于服装设计很有一定的造诣，爱穿着打扮的女孩子经常光顾这里。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"nvrenjie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}