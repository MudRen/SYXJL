#include <ansi.h>

#include <room.h>

inherit ROOM;

void create()

{

         set("short","小门");

         set("long", @long

这里是一道圆形小门，小门的南面是一条长廊，长廊里面人来人往，所

有的人都在忙着自己的事情。

long);

         set("exits", ([

             "north" : __DIR__"c15-3",

             "south" : __DIR__"c15-4",

]));

         setup();

         replace_program(ROOM);

}

