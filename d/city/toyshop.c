inherit ROOM;
void create()
{
        set("short", "鹿鼎玩具有限公司扬州城总代理");
        set("long", @LONG
这里是鹿鼎玩具有限公司扬州城总代理，柜台中都摆放着各式各样的玩具
供你尽情挑选。墙上挂了一块牌子(paizi)，写着最新的通告。
LONG
        );

        set("no_fight", 1);
        set("no_study", 1);
        set("no_sleep_room",1);
        set("no_yun",1);

        set("item_desc", ([
                "paizi" : "新玩具过几天就要到货，本店信誉第一，童叟无欺。\n",
        ]));

        set("objects", ([
                __DIR__"npc/songlaoban" : 1,
        ]));

        set("exits", ([
                "westdown"  : __DIR__"kedian",

        ])); 
        setup();
}


