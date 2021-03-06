
// Room: /chang'an/nandajie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "南大街");
        set("long", @LONG
这里是长安城南大街的南头。南面就是朱雀内门。有不少头戴儒巾的
读书人在东面出入，无非是去观赏或者临摹碑林里书法大家的手笔。西面
是一家书店。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"beilin",
                "south" : __DIR__"southgate1",
                "west"  : __DIR__"shudian",
                "north" : __DIR__"gulou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
