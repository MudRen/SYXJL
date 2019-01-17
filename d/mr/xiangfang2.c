#include <ansi.h>

#include <room.h>

inherit ROOM;

void create()

{

         set("short","厢房");

         set ("long",@long

这是一间厢房, 里面摆设简单, 只有一张床, 一张书桌和一把椅子。

long);

         set("no_fight", 1);

         set("sleep_room", 1);

         set("exits",([

             "west" : __DIR__"houting",

             "east" : __DIR__"c15-1",

             "north" : __DIR__"shufang",

]));

         setup();

         replace_program(ROOM);

}

