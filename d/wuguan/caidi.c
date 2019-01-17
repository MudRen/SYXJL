// Room: /d/wuguan/caidi.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�˵�");
        set("long", @LONG
�����ǿ�˵أ����ڳ��ڵò������õ��չˣ��˵����Ӳݴ�����
�ֵĲ˶����Ʋ��ã�����ģ��ض����ˡ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "west" : __DIR__"houyuan2",
        ]));
        set("objects", ([
                __DIR__"npc/cyguanshi" : 1,
        ]));
            
        setup();
}



void init()
{
        add_action("do_work", "chu");
}

int do_work(string arg)
{
        object me;
        int costj, costq,i;
        me = this_player();
        i = 10+random(5);
        if (me->query_temp("job1")!=1) return notify_fail("��Ҫ��ʲô��\n");   
        if( !arg && arg !="��") return notify_fail("��Ҫ��ʲô��\n");   
        if (me->is_busy())
                return notify_fail("��������æ�������ء�\n");             
        if( !present("chutou", this_player()) ) 
        {  
         	tell_object(me,"\n������ʲô�����ݣ�������\n");      
                return 1;
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;

                
        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
        {
               message_vision("$N��һ�ɣ���С�ĳ������Լ��Ľ��ϣ�\n",me);
               me->unconcious();
               return 1;
        }        
        if(me->query_temp("task")==1)
        {
        	message_vision(RED"�˵ع��¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	return 1;
        }        	
        if(me->query_temp("chu")<i) 
        {        
        	message_vision("$N�����ͷ�����ŵ��ϵ��Ӳݳ���������\n",me);      	  
        
        	me->receive_damage("jing", costj);
        	me->receive_damage("qi", costq);       
       		me->start_busy(1);
        	if ( (int)me->query_skill("staff", 1) < 20 && random(10)>5 )
        	{  
                	write(HIM"���ڳ����ж����ȵ��÷���Щ��ᣡ\n"NOR);
                	me->improve_skill("staff", (int)(me->query("int") / 10));
                }       		
        	me->add_temp("chu",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"�˵ع��¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	me->set_temp("task",1);        	  
                  me->delete_temp("chu");
        	return 1;     	
        }
}
