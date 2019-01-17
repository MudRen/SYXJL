// Room: /u/xdd/gumu/gmgdao.c

#include <ansi.h>

#include <room.h>

inherit ROOM;

int a = random(2);

int b = random(2);

int c = random(2);



void create()

{    

     

     set("short", "石室");

     set("long", @LONG

这是一间很小的石室，正对你有扇巨大的石门，门上却并排着三只精工雕

刻的猛兽头像，皆栩栩如生，张牙呼之欲出，左为青龙，右为白虎，中为棕狮。

兽口中各具机簧，看来可以推拉来启动不知什么机关。

LONG

        );



     set("exits", ([

         "out" : __DIR__"gmlg2",

         ]));



        while (!a && !b && !c) {

                a = random(2);

                b = random(2);

                c = random(2);

        }

        set_temp("mark/left", 0);

        set_temp("mark/middle", 0);

        set_temp("mark/right", 0);

        setup();

   }



void init()

{

     add_action("do_pull", "pull");

     add_action("do_push", "push");

 }



int do_pull(string arg)

{    

     object me = this_player();

     if ( arg == "left") {

        if (query_temp("mark/left") > 0)

                return notify_fail("龙头中的机簧已经拉到头了。\n");

        message_vision("$N扳动龙头中的机簧，用力向外拉了一下。\n", me);

        message("vision", "石门后传来轰隆隆的声音。\n", me);

        add_temp("mark/left", 1);

        return 1;

     }    

     if ( arg == "middle") {

        if (query_temp("mark/middle") > 0)

                return notify_fail("狮头中的机簧已经拉到头了。\n");

     message_vision("$N扳动狮头中的机簧，用力向外拉了一下。\n", me);

     message("vision", "石门后传来轰隆隆的声音。\n", me);

      add_temp("mark/middle", 1);

     return 1;

}

     if (arg == "right") {

        if (query_temp("mark/right") > 0)

                return notify_fail("虎头中的机簧已经拉到头了。\n");

     message_vision("$N扳动虎头中的机簧，用力向外拉了一下。\n", me);

     message("vision", "石门后传来轰隆隆的声音。\n", me); 

    add_temp("mark/right", 1);

     return 1;

}

     if ( arg == "gate")

             return notify_fail("这扇门好象是推的。\n");  

      write("你要拉什么？\n");

      return 1;

}



int do_push(string arg)

{    object me = this_player();

     if ( arg == "left") {

        if (query_temp("mark/left") < 0)

                return notify_fail("龙头中的机簧已经推到头了。\n");

     message_vision("$N扳动龙头中的机簧，用力向里推了一下。\n", me);

     message("vision", "石门后传来轰隆隆的声音。\n"NOR, me);

     add_temp("mark/left", -1);

     return 1;

}    

     if ( arg == "middle") {

        if (query_temp("mark/middle") < 0)

                return notify_fail("狮头中的机簧已经推到头了。\n");

     message_vision("$N扳动狮头中的机簧，用力向里推了一下。\n", me);

     message("vision", "石门后传来轰隆隆的声音。\n"NOR, me);

      add_temp("mark/middle", -1);

     return 1;

}

     if (arg == "right") {

        if (query_temp("mark/right") < 0)

                return notify_fail("虎头中的机簧已经推到头了。\n");

     message_vision("$N扳动虎头中的机簧，用力向里推了一下。\n", me);

     message("vision", "石门后传来轰隆隆的声音。\n", me); 

    add_temp("mark/right", -1);

     return 1;

}

     if ( arg == "gate")

{     

      if (me->query("qi") < 20 || me->query("neili") < 100)

      return notify_fail("你身体虚弱，无力推动石门。\n");

      if (query_temp("mark/left") == a && query_temp("mark/middle") == b

      && query_temp("mark/right") == -c)

{     message_vision("$N用力推动石门，石门应手而开。\n", me);

      set("exits/enter", __DIR__"gmlg3");

      remove_call_out("shut_gate");

      call_out("shut_gate", 10);

      me->add("combat_exp", random(10));

      set_temp("mark/left", 0);

      set_temp("mark/middle", 0);

      set_temp("mark/right", 0);

      return 1;    

}

      message_vision("$N用力推向石门，大门却纹丝不动。\n", me);

      me->receive_damage("qi", 20);

      me->add("neili", -100);

      return 1;

}      

      write("你要推什么？\n");

      return 1;

}

                

void shut_gate()

{  

      if ( !query("exits/enter")) return;

      message("vision", "石门缓缓启动，自己又重新关起来。\n", this_object());

      delete("exits/enter");

}



