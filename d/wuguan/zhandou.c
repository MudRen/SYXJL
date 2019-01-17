// Room: /d/wuguan/zhandou.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "如何战斗");
        set("long", @LONG
武林中不能没有战斗，更加不可以没有打打杀杀。要在武林中立
足，就必须学会如何生存，只有战斗！才能使你能在这个弱肉强食、
适者生存的江湖上活下去。所以，一定要知道如何战斗，就等于知道
如何生存一样。不懂得战斗，又如何成为高手呢？
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "north" : __DIR__"wuguandayuan",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoqian" : 1,
        ]));
                
        setup();
        replace_program(ROOM);
}
