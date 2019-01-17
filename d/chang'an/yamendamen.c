
// Room: /chang'an/yamendamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "衙门");
        set("long", @LONG
这里是衙门大门，两扇朱木大门呈八字敞开。“肃静”“回避”的牌子分
放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙
役在门前巡逻
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"dongdajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}