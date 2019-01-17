  // /d/kunllun/xlgf_1.c



#include <ansi.h>

inherit ROOM;



void create()

{

        set("short", "小练功房");

        set("long", @LONG

这是掌门夫人专用的打坐读书的地方。夫人不喜任何装饰, 所以室内只

有一个小小的蒲团。墙上悬着两三把木剑，门后有一个香炉(xianglu)。地

面上清晰地绘着阴阳八卦之图案，想必是用于辅助修习昆仑派名动天下的正

两仪剑法，北边有一扇小门通向观花亭。

LONG

        );

        set("exits", ([

                "north" : __DIR__"guanhuat",

                "south" : __DIR__"ceting_w",

        ]));

        



        set("item_desc", ([

                "xianglu" :

"这是由青铜铸成的香炉，重约二百多斤，炉身纹有九龙戏珠的图案。

炉内火势正旺，正是炼丹的紧要关头! 为了保持火势，必须不停地向

炉口扇(shan)风。\n",

        ]));



        set("dan_count", 6);

        setup();

}



void init()

{

        add_action("do_shan", "shan");

}



int do_shan(string arg)

{       mapping fam;

        object me;
        int i, costj, costq;



        me = this_player();

        if (me->is_busy())

         {write("你现在正忙着呢！\n");return 1;}

        if (me->is_fighting())

         {write("你正在战斗中，无法专心干活！\n");return 1;}



        if ( arg != "xianglu" )

            {    message_vision("$N摆了摆手，象是在扇凉！\n",me);

                 return 1;

             }

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "昆仑派")

               return notify_fail("你与本派素无来往，不必在此浪费体力!\n");

        costj = 1000 / (int)me->query("con");

        costj = random(costj);

        costq = 1500 / (int)me->query("str");

        costq = random(costq);



        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){

        message_vision("$N用力过猛，一不留神头嗑到香炉上！\n",me);

        me->unconcious();return 1;}

        

        me->receive_damage("jing", costj);

        me->receive_damage("qi", costq);       



        message_vision("$N用力呼哧呼哧地扇着火。\n", me);



        if ( (int)me->query_skill("strike", 1) < 31)

                {

                        write(HIY"你手臂来回用力，进退之中似乎对基本掌法有些领悟。\n"NOR);

                        me->improve_skill("strike", (int)(me->query("int") / 2));

                }

        if ( (int)me->query_skill("parry", 1) < 31)

                {

                        write(HIY"你手臂来回用力，进退之中似乎对基本招架有些领悟。\n"NOR);

                        me->improve_skill("parry", (int)(me->query("int") / 2));

                }

          if ( (int)me->query("combat_exp") < 15000 && me->query("neili") > 100) {

             me->add("combat_exp", (int)(me->query("con") / 6));

             me->add("neili", - random(50));

          }

        i = (int)me->query("int") * (int)me->query("str") / 4;

        i = i + (int)me->query("kar") / 3 - 20+random(8); 

        return 1;}



