
// Room: /chang'an/caizhuhouyuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "财主后院");
        set("long", @LONG
这里是财主后院，各种古玩琳琅满目，商周青铜、唐三彩……，应有
尽有，只要拥有一件，就够你吃一辈子了。高员外正坐在竹榻上，慢幽幽
地喝着清茶
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"caizhudayuan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}