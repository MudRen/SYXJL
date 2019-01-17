// Room: /d/wuguan/mafang.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "马房");
        set("long", @LONG
这里是马房，里面臭烘烘的，养了几十匹马，你看过去，马身上
都很脏了，该洗洗了，旁边有个水池，里面有些清水。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"houyuan1",
        ]));
        set("objects", ([
                __DIR__"npc/mfguanshi" : 1,
        ]));
        
        setup();
}

void init()
{
        add_action("do_work", "sao");
}

int do_work(string arg)
{
        object me;
        int costj, costq;
        me = this_player();
        if (me->query_temp("job5")!=1) return notify_fail("你要干什么？\n");   
        if( !arg && arg !="马房") return notify_fail("你要打扫哪里？\n");   
        if (me->is_busy())
                return notify_fail("你现在正忙不过来呢。\n");             
        if( !present("saozhou", this_player()) ) 
        {  
         	tell_object(me,"\n你想用什么来打扫，用手扫吗？\n");      
                return 1;
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;


        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
        {
             message_vision("$N脚一滑，不小心滑倒在粪堆里，吃了一大口马粪！\n",me);
             me->add("food", 10);
             me->unconcious();
             return 1;
        }

        if(me->query_temp("task")==1)
        {
        	message_vision(RED"马房管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	return 1;
        }   
        if(me->query_temp("sao")<(10+random(5))) 
        {        
        	message_vision("$N找了个地方开始扫了起来，真够臭的，你不由闭紧了呼吸。\n",me);      	  
        	        
        	me->receive_damage("jing", costj);
        	me->receive_damage("qi", costq);       

        	if ( (int)me->query_skill("club", 1) < 20 && random(10)>5 )
        	{  
              		write(HIM"你在扫地中对于棍的用法有些体会!\n"NOR);
              		me->improve_skill("club", (int)(me->query("int") / 10));
              	}
       		me->start_busy(1);
        	me->add_temp("sao",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"马房管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	me->set_temp("task",1);        	  
                  me->delete_temp("sao");
        	return 1;     	
        }
}
