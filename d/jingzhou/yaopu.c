inherit ROOM;

void create()
{
        set("short", "药铺");
        set("long", @LONG
        这是一家药铺，小小的房间里到处都是难闻的药材味道，靠在柜台旁
边的一名郎中正在跟一名病人把着脉，一副很专心地样子。一名小伙计站
在柜台后拿着天平忙得要死。柜台上贴着一张价目表(jiamubiao)。
LONG
        );
//        set("outdoors", "jingzhou");
        set("item_desc", ([
                "jiamubiao" : "本店出售以下药品：
金创药：\t五十两白银
养精丹: \t二十两白银
其他神药与老板面议。\n",
        ]));


        set("objects", ([
                "/d/jingzhou/npc/huoji" : 1,
        ]));

        set("exits", ([
                "east"  : __DIR__"nanmendajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

