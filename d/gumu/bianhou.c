// Room: bianhou.c

// csy 1998.12.29

#include <ansi.h>

inherit ROOM;



void create()

{

      set("short",HIB"匾后"NOR);

      set("long", @LONG

这里就是古墓中堂匾额之后，黑漆漆的什么都看不清楚。

LONG

    );

      

      set("objects",([

         __DIR__"obj/silkey" : 1,   

      ]));



      setup();

}



void init()

{

     add_action("do_jump","jump");

}



int do_jump(string arg)

{

        object me,room;

        me=this_player();  

        if (arg!="down") return 0;

        message("vision",me->name()+"一纵身，跳了下去。\n",this_object());

        if(room=find_object(__DIR__"gmzt"))

        message("vision",me->name()+"从匾额上跳了过来。\n",room);

        me->move(__DIR__"gmzt");

        return 1;

}



