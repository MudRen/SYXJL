inherit ROOM;

void create()
{
        set("short", "天魔阵");
        set("long", @LONG
这就是东方不败当年逃避任我行追杀的地方，茂密的草木
使你连方向都弄不清楚，一个声音在你的脑海中回荡：
        “别出去了，就留在这迷阵吧...........!!!!”
LONG
        );
        set("outdoors", "oldpine");
        
        setup();
}

void reset()
{
        ::reset();
        set("exits", ([ /* sizeof() == 5 */
          "south" : __DIR__"climb" + (random(10)+1),
          "north" : __DIR__"climb" + (random(10)+1),
          "west" : __DIR__"climb" + (random(10)+1),
          "east" : __DIR__"climb" + (random(10)+1),
          "out" : __DIR__"shandong2",
        ]));
}

int valid_leave(object me, string dir)
{
        if ( dir == "west")
            me->add_temp("mark/steps",1);
        if ( dir == "east")
            me->add_temp("mark/steps",-1);

        if ( dir == "south")
            me->add_temp("mark/steps",1);
        if ( dir == "north")
            me->add_temp("mark/steps",-1);

        if (me->query_temp("mark/steps") == 10)
         {
            me->move(__DIR__"climb4");
            me->delete_temp("mark/steps");
             return notify_fail("你累得半死，终於走出了迷阵。\n");
         }  

     if (me->query_temp("mark/steps") == -10)
            {  
               me->move(__DIR__"climb4");
           me->delete_temp("mark/steps");
             return notify_fail("你累得半死，终於走出了迷阵。\n");
        }

        return ::valid_leave(me,dir);
}
