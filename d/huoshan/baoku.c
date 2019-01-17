
// Room: /huoshan/baoku.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "宝库");
        set("long", @LONG
你一进来就被一阵珠光宝气冲昏了头脑，你没想到世界上居然
还有这么大的藏宝库，这里的珠宝完全是堆积如山，随手拿取一件
都足够你受用不尽了。奇怪的是在西面有一个真人般大小的金人，
做工十分粗糙，身上到处是刀剑的痕迹，虽说是金子打造而成，但
和这里其他做工精细的金制品比较起来，完全是宝物中的垃圾了。
墙上写着几个大字：擅动宝藏者，死！
LONG
        );
//        set("outdoors", "lvzhou");
        set("exits", ([
                "out"  : __DIR__"shimen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}