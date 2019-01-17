// Room: /d/wuguan/mafang.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��");
        set("long", @LONG
������������������ģ����˼�ʮƥ���㿴��ȥ��������
�������ˣ���ϴϴ�ˣ��Ա��и�ˮ�أ�������Щ��ˮ��
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
        if (me->query_temp("job5")!=1) return notify_fail("��Ҫ��ʲô��\n");   
        if( !arg && arg !="��") return notify_fail("��Ҫ��ɨ���\n");   
        if (me->is_busy())
                return notify_fail("��������æ�������ء�\n");             
        if( !present("saozhou", this_player()) ) 
        {  
         	tell_object(me,"\n������ʲô����ɨ������ɨ��\n");      
                return 1;
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;


        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
        {
             message_vision("$N��һ������С�Ļ����ڷ�������һ�����࣡\n",me);
             me->add("food", 10);
             me->unconcious();
             return 1;
        }

        if(me->query_temp("task")==1)
        {
        	message_vision(RED"�����¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	return 1;
        }   
        if(me->query_temp("sao")<(10+random(5))) 
        {        
        	message_vision("$N���˸��ط���ʼɨ���������湻���ģ��㲻�ɱս��˺�����\n",me);      	  
        	        
        	me->receive_damage("jing", costj);
        	me->receive_damage("qi", costq);       

        	if ( (int)me->query_skill("club", 1) < 20 && random(10)>5 )
        	{  
              		write(HIM"����ɨ���ж��ڹ����÷���Щ���!\n"NOR);
              		me->improve_skill("club", (int)(me->query("int") / 10));
              	}
       		me->start_busy(1);
        	me->add_temp("sao",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"�����¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	me->set_temp("task",1);        	  
                  me->delete_temp("sao");
        	return 1;     	
        }
}
