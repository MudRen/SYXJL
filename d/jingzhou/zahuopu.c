
// Room: /jingzhou/zahuopu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "杂货铺");
        set("long", @LONG
这是家小小的杂货铺，商品看起来还算丰富，大都是一些日常用品。
掌柜笑容可鞠地站在柜台旁，招呼着过往行人。据说私底下他也卖一些
见不得光的东西。墙上挂着一块招牌(zhaopai)。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"sanyijie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}