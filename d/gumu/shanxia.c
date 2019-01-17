// shanxia.c By csy 98/12

inherit ROOM;
#include <ansi.h>
int get_object(object ob);
void create()
{
    set("short", HIG"终南山凹"NOR);
    set("long", @LONG
这里是终南山凹，四周一片清寂，只闻泉声鸟语，杳无人迹。四下里山石
嶙峋，树木茂密，隐蔽之处甚多。在不远处的灌木丛中，隐隐约约的好象有个
小山洞(dong)。
LONG
        );

    set("item_desc", ([
           "dong" : HIB"一个黑乎乎的小洞，不知道通向哪里？\n"NOR,
    ]));

    set("outdoors","古墓");

    set("exits", ([
                "northwest" : __DIR__"xiaolu3",
    ]));
    
    set("coor/x",-80);
	set("coor/y",150);
	set("coor/z",50);
	set("coor/x",-80);
	set("coor/y",150);
	set("coor/z",50);
	set("coor/x",-80);
	set("coor/y",150);
	set("coor/z",50);
	set("coor/x",-80);
	set("coor/y",150);
	set("coor/z",50);
	setup();
}

void init()
{ 
      add_action("do_zuan","zuan");
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int do_zuan(string arg,object *obj)
{
      object me=this_player();
      object *inv = deep_inventory(me); 
      mapping fam;
      if (me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着哪！\n");       
      if ( arg=="dong"){
        if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
             return notify_fail("你不是古墓派传人，不要再在古墓附近久留了。\n");
        if(me->query_temp("ride_horse"))
             return notify_fail("你骑在马上，怎么进山洞？\n");
        if ( me->query_skill("yunu-xinjing", 1) > 119 ){
        obj = filter_array(inv,(:get_object:));
        if(sizeof(obj)){
         write ("你摸索着进入山洞，由于背带东西太多，一头撞在山壁上。\n");
         me->unconcious();
         me->move(__DIR__"shanxia");
         return 1;
         }         
         me->move(__DIR__"dongkou");
         message_vision(HIY"$N一矮身穿过小洞来到洞口，只见阳光耀眼，浓荫匝地。\n"NOR,me);
         return 1;
         }
        return notify_fail("这么小的山洞，你钻的进去吗？\n");
       }
     return notify_fail("你往哪里钻？\n");
}


