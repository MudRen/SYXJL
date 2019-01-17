// Room: gudi.c





#include <ansi.h>

inherit ROOM;



void create()

{

        set("short", "谷底");

        set("long", @LONG

这是一个鸟语花香的世外桃源，几头小鹿在安详得喝着清澈

的泉水，鸟语山空，美丽的百灵鸟在甜蜜地歌唱，几只蝴蝶在花

丛中飞来飞去，自由自在，还有几只猴子在树梢上奇怪地看着你

这位不速之客，其中一只大白猿“吱吱”地对你叫，是欢迎呢，

还是讨厌呢？谷旁有两三根古藤(teng)。

LONG



        );

set("objects",([

__DIR__"npc/baiyuan" : 1,

]));

        set("no_clean_up", 0);

        set("item_desc", ([

                "teng": "这是一根老山藤。\n"

                ]) );



        setup();

}

void init()

{

        add_action("do_climb", "climb");

}

int do_climb(string arg)

{

        object me=this_player();



        if( !arg || arg=="" ) {write("你要爬什么？\n");return 1;}



        if( arg=="teng" ) {

                write("你抓着山藤，努力向上爬去....\n");

if((int)me->query_skill("dodge",1)>=40)

                {write("爬呀爬呀，爬呀爬呀，你终于爬到了山顶。\n");

                me->move(__DIR__"shandao1");                

                 return 1;}

                write(HIR"突然间，你一不留意，就跌了下去。\n"NOR);



                me->add("jing",-40);

                me->add("qi",-40);

                me->improve_skill("dodge", random(100));

                me->unconcious();



                return 1;



                 }

}



