// Room: /d/wuguan/mufang.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ľ��");
        set("long", @LONG
һ���ݣ���ͱ��޴�ĺ�������ס�ˣ�������˺ö೤��ľͷ��׼��Ҫ��
����õģ���������ȥ��ǰ�ȵðѳ�ľͷ��̳�һ�ؽصģ��ź��ø�ͷ������
�㿴���������ڷ����ľ��š�
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
        if (me->query_temp("job2")!=1) return notify_fail("��Ҫ��ʲô��\n");   
        if( !arg && arg !="ľͷ") return notify_fail("��Ҫ��ʲô��\n");   
        if (me->is_busy())
                return notify_fail("��������æ�������ء�\n");             
        if( !present("juzi", this_player()) ) 
        {  
         	tell_object(me,"\n������ʲô����ľͷ�����־���\n"); 
         	return 1;     
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
        {
                message_vision("ľͷͻȻ���ˣ�$Nһû�����õ�������ľͷ������ͷ�ϣ�\n",me);
                me->unconcious();
                return 1;
        }
        if(me->query_temp("task")==1)
        {
        	message_vision(RED"ľ�����¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	return 1;
        }        	        
        if(me->query_temp("ju")<(10+random(5))) 
        {        
        	message_vision("$N����һ��ľͷ����������������\n",me);      	  
        
        	me->receive_damage("jing", costj);
        	me->receive_damage("qi", costq);       
       		me->start_busy(1);
        	if ( (int)me->query_skill("hand", 1) < 20 && random(10)>5 )
        	{  
                	write(HIM"���ھ�ľͷ�������жԻ����ַ���Щ��ᣡ\n"NOR);
                	me->improve_skill("hand", (int)(me->query("int") / 10));
                }       		
        	me->add_temp("ju",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"ľ�����¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	me->set_temp("task",1);
                  me->delete_temp("ju");
        	return 1;     	
        }
}

