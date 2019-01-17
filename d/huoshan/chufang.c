
// Room: /huoshan/chufang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "厨房");
        set("long", @LONG
一间宽敞明亮的餐厅，你可以在任何时候在这里填饱肚子。好
象这里的人吃饭都很不准时，总是没见几个人在这里吃饭，饭菜的
色香味一应俱全，足可以刺激你的食欲了。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"zoulang1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}