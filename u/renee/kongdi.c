// renee

#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_lingwu(string arg);

void create()
{
    set("short", GRN "竹林空地"NOR);
    set("long", @LONG
风吹过竹林发出动听的旋律，这里四周长满青竹， 据说张真人经常
来这里炼剑。仔细一看，青竹上有不少剑痕，离这里不远有间小屋。
LONG
	);
	
	set("exits", ([
	"northwest"      : __DIR__"zhulin14",
]) );


 	setup();

}

void init()
{
        add_action("do_lingwu", "kan");
}

int do_lingwu(string arg)
{
        object me;
        me = this_player();
	  if ( !arg || arg != "jianhen" )
        return notify_fail("你想领悟什么! \n");
	  
 	  if( (int)me->query_skill("taiji-jian", 1) < 200 )
                return notify_fail("你的太极剑法不够娴熟，无法悟出归真一剑。\n");

	  if(me->query_temp("wudang/quest1")==1)
	  {
        me->set("wudang/guizhen",1);
        message_vision("$N你瞧了半天，越看越是神往，仿佛看到张三丰在炼剑。\n" 
                        "每一道剑痕都包含着太极剑中精髓。你悟出了『归真一剑』的精髓\n" , me);
        return 1;
         }
        else
         {
        tell_object(me,"What ?\n" );
        return 1;
         }
}
