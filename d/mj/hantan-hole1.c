// Room: hantan-hole1.c



inherit ROOM;



void create()

{

        set("short", "密洞");

        set("long", @LONG

一个深深的洞，洞里面仿佛有一块千年寒冰，洞里弥漫着凉气。

LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "west" : __DIR__"hantan",

]));

        set("no_clean_up", 0);



        setup();

}

void init()

{

        add_action("do_tang", "tang");

}

int do_tang(string arg)

{

object obj;
        obj = this_player();

        if( !arg || arg=="" ) return 0;

        if ((int)this_player()->query_skill("force", 1) < 50) {

                message_vision(

"$N的基本内功不够，无法承受千年寒冰的冷气！\n",this_player());

              return 1;

                            }

        if ( (int)this_player()->query("jing") < 30 || (int)this_player()->query("qi") < 60) {

                message_vision(

"$N已经受不了千年寒气的侵袭！\n",this_player());

               return 1;

                }

        if( arg=="hanbing" ) {

                if (!query("hs_trigger")){

                message_vision(

"$N爬上千年寒冰，躺在上面，暗运内功，以抗寒气。\n"

".....慢慢地进入了忘我的状态....\n", this_player());

       this_player()->add("qi", (-1)*80);

      this_player()->add("jing", (-1)*60);

                this_player()->add("neili", 20);

                this_player()->set_temp("marks/睡", 1);

                return 1;

                }

                message_vision(

"$N疯了！这里不能躺！\n", this_player());

                return 1;

        }

        return 0;

}





