
// Room: /jingzhou/bingying.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "兵营");
        set("long", @LONG
这里是兵营，密密麻麻到处都是军士，正在武将的指挥下列队操练，
有的独自在练功。南墙下坐着主帅，不动声色地寻视着四周。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"bingyingdamen",
         ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}