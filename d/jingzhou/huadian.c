
// Room: /jingzhou/huadian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "花市");
        set("long", @LONG
你忽然感到眼前一花，仿佛已经忘记了你正身处与一座喧闹的城市里，
身边是盆栽的各类鲜花，争相怒放，各展娇柔，令你不禁想买上一些才好。
店主是个漂亮的女孩子，看来并不十分擅长做生意，只是腼腆地站在一边，
涨红了脸，真是人面桃花，谁说不是一道景致？
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nvrenjie3",
                "north"  : __DIR__"yingdulu",
        ]));
        set("objects", ([
                __DIR__"npc/flowersg" : 1,
                __DIR__"npc/huatong" : 1,                
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}