// fufengshan.c (kunlun)



#include <ansi.h>

#include <room.h>

inherit ROOM;



int do_climb();



void create()

{

                  set("short", "扶峰山");

                  set("long", @LONG

一座大山出现在你的面前，这就是天下闻名的扶峰山了。扶峰山极高且

十分陡峭，山腰以上尽没入茫茫云海，峰顶终年积雪，山腰以下却是郁郁苍

苍，林木茂密，花团锦簇，春意烂漫。忽听得不远处的树林里传来一阵悠扬

的萧音，仿佛有什么高人在这里隐居。

LONG

                  );

                  set("outdoors", "kunlun");



                  set("exits", ([

                                         "enter" : __DIR__"houyuan.c",

                                         "northeast" : __DIR__"bainiushan.c",

                  ]));



                  set("objects",([

                "/d/kunlun/npc/gaozecheng.c" :   1,

                "/d/kunlun/npc/jiangtao.c" :   1,

                ]));

                  set("no_clean_up",0);

create_door("enter", "小门", "out", DOOR_CLOSED);



                  setup();

}



void init()

{

                  add_action("do_climb", "climb");

}

int do_climb()

{

                  object me= this_player();



                   if( random((int)me->query_skill("dodge",1))<=30) {

                                         me->receive_damage("qi", 50);

                                         me->receive_wound("qi", 50);

                                         message_vision(HIR"$N一不小心脚下踏了个空... 啊...！\n"NOR, me);

                                         me->move(__DIR__"fufengshan.c");

                                         tell_object(me,

                  HIR"你从山上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);

                                           message("vision",HIR"只见" + me->query("name") +

                      "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), ({me}));

                return 1;

                  }



                                         message("vision",

                me->name() + "提一口真气，足尖连点数下，发足向山上奔去。\n",

                                         environment(me), ({me}) );

           me->move(__DIR__"sanshengao.c");

                                         return 1;

}





