inherit ROOM;
void create()
{
        set("short", "鼓楼二层");
        set("long", @LONG
这里就是鼓楼二楼了。第二层楼上复绿琉璃瓦，重檐歇山顶；面阔各
为七间，进深均为三间，四周另有走廊。每层正面十根红柱，九个开间。
北设巨鼓一面，击鼓为全市居民报时，鼓楼因此得名。�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "down"  : __DIR__"gulou",
                "up"    : __DIR__"gulousanceng",                             
        ]));
        set("objects", ([
                __DIR__"npc/laohan" : 1,

        ]));


        setup();
}
int valid_leave(object me, string dir)
{

        if ( !me->query_temp("up") && dir == "up" )
                return notify_fail("老汉伸手一拦：“这里可是官家的地方，你想这样随便就进去啦！”\n");

        return ::valid_leave(me, dir);
}
