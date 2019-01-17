
// Room: /chang'an/mugongfang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "木工房");
        set("long", @LONG
你刚刚走进门，就觉得一阵热浪扑面而来。这里正是一家铁匠铺，两
个打着赤膊的汉子正拿着大铁锤敲击着烧得火红的铁坯。一个老汉正在一
边拉扯着风箱。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"xidajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}