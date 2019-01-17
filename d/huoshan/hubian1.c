
// Room: /huoshan/hubian1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "湖边");
        set("long", @LONG
好清的一湖水呵。湖面平静地象一面镜子，四周长满了郁郁葱
葱的胡杨树，因为你的到来，惊起了几只正在树林里的栖鸟，大漠
里带来的一身疲惫顿时烟消云散，你不由得对这潮湿的空气做了几
个深呼吸。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"hubian2",
                "northwest" : __DIR__"hubian3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}