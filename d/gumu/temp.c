// Room: /u/xdd/gumu/lyy.c

// Modify By csy 98/12

inherit ROOM;

#include <ansi.h>

void create()

{

     set("short",YEL"老妪岩"NOR);

     set("long", @LONG

山道此处遽然变窄，遮天古木令天地顿暗。迎面又一大岩石当道，形状阴

森可怖，自空凭临，宛似一个老妪弯腰俯视。说不出的鬼气弥漫，岩后昏黑中

不知藏有多少杀机。

LONG        );



     set("outdoors","古墓");

    

     set("exits", ([

         "east" : __DIR__"shulin1",

         "northdown" : __DIR__"bzy",

       ]));

     

     setup();

}

int valid_leave(object me, string dir)

{

        if (dir=="east" )

        {

        if(me->query("can_ride"))

                {

                                        return 0;



                }

        

        if(me->query_temp("ride_horse"))

        return notify_fail("里面荆棘丛生，骑马不宜入内\n");

        }

        return ::valid_leave(me, dir);

}



