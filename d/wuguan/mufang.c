// Room: /d/wuguan/mufang.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "木房");
        set("long", @LONG
一进屋，你就被巨大的轰鸣声吵住了，这里堆了好多长的木头，准备要做
柴火用的，但是在送去柴房前先得把长木头锯短成一截截的，才好用斧头劈开。
你看见几个人在费力的锯着。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "west" : __DIR__"houyuan1",
        ]));
        set("objects", ([
                __DIR__"npc/mufguanshi" : 1,
        ]));
                
        setup();
}


void init()
{
        add_action("do_work", "ju");
}

int do_work(string arg)
{
        object me;
        int costj, costq;
        me = this_player();
        if (me->query_temp("job2")!=1) return notify_fail("你要干什么？\n");   
        if( !arg && arg !="木头") return notify_fail("你要锯什么？\n");   
        if (me->is_busy())
                return notify_fail("你现在正忙不过来呢。\n");             
        if( !present("juzi", this_player()) ) 
        {  
         	tell_object(me,"\n你想用什么来锯木头，用手锯吗？\n"); 
         	return 1;     
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
        {
                message_vision("木头突然断了，$N一没留神，让弹起来的木头砸在了头上！\n",me);
                me->unconcious();
                return 1;
        }
        if(me->query_temp("task")==1)
        {
        	message_vision(RED"木房管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	return 1;
        }        	        
        if(me->query_temp("ju")<(10+random(5))) 
        {        
        	message_vision("$N摆正一根木头，慢慢锯了起来。\n",me);      	  
        
        	me->receive_damage("jing", costj);
        	me->receive_damage("qi", costq);       
       		me->start_busy(1);
        	if ( (int)me->query_skill("hand", 1) < 20 && random(10)>5 )
        	{  
                	write(HIM"你在锯木头的推拉中对基本手法有些体会！\n"NOR);
                	me->improve_skill("hand", (int)(me->query("int") / 10));
                }       		
        	me->add_temp("ju",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"木房管事对$N说：干的不错，好了，你可以回去覆命(task ok)了。\n"NOR,me);
        	me->set_temp("task",1);
                  me->delete_temp("ju");
        	return 1;     	
        }
}

