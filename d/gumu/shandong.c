// shandong.c By csy 98/09



inherit ROOM;

#include <ansi.h>

void create()

{

    set("short", HIY"大山洞"NOR);

    set("long", @LONG

这洞其实甚浅，行不到三丈，已抵尽头，尽头处有个小洞(dong)可通往山

后。洞中除了一张石桌、一张石凳之外更无别物。洞角有一堆乱石高起，极似

一个坟墓，洞壁上似乎写得有字(zi)，只是尘封苔蔽，黑暗中瞧不清楚。

LONG

        );



    set("item_desc", ([

           "zi" : HIY"\t\t纵横江湖三十馀载，杀尽仇寇，

\t\t败尽英雄，天下更无抗手，

\t\t无可柰何，惟隐居深谷，以雕为友。

\t\t呜呼，生平求一敌手而不可得，诚寂寥难堪也。\n 

\t\t\t\t\t剑魔独孤求败\n"NOR,

           "dong" : "从洞外透来一丝光亮，使得原本幽暗的山洞显出一份生气。\n",

    ]));



    set("exits", ([ 

                "out"  : __DIR__"shanlu6",

    ]));

    

    setup();

}



void init()

{ 

      add_action("do_zuan","zuan");

}



int do_zuan(string arg)

{

      object me=this_player();

      if (me->is_busy() || me->is_fighting())

         return notify_fail("你正忙着哪！\n");

      if ( !arg || arg != "dong")

         return notify_fail("你往哪里钻啊？\n");

      if ( arg=="dong")

         me->move(__DIR__"shanlu7");

         message_vision(HIY"$N一矮身穿过小洞来到洞後，只见树木苍翠，山气清佳。\n"NOR,me);

         return 1;

}



