
// Room: /jingzhou/jiangjunfu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "将军府");
        set("long", @LONG
看起来此地的守备还算清廉，宅子门口也对石狮子也没放。由于现在需
要不停往襄阳调运军需物资，以防止蒙古人继续南侵，荆州守备也是忙得焦
头烂额，白日里难得在家，所以干脆大门紧闭，只有两名亲兵看着大门。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"jingzhonglu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}