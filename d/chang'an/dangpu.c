
// Room: /chang'an/dangpu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "当铺");
        set("long", @LONG
这是家远近闻名的当铺，三开间的门面，一块写着『刘记当铺』四个
金字的黑匾，足足七尺高的紫檀木的柜台被磨得光可照人，你一进去就有
一种压抑和悲怅的感觉，柜台后的刘老板也不抬的只顾拨拉着算盘，柜台
上方挂着一块花木牌子（paizi） 。据街坊们说当铺给的价还不算最坏，
并且从来不问货的来处，除了活人什么都收，所以生意很不错。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"beidajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}