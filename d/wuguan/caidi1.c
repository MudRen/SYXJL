// Room: /d/wuguan/caidi1.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�˵�");
        set("long", @LONG
�����ǿ�˵أ��˵����м��ڴ�ף�����ʢ����ˮ�����ǲ˵ؿ�����
�������ˣ����ò�����ĳ��ţ���������ȱˮ̫���ˡ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"houyuan2",
        ]));
        set("objects", ([
                __DIR__"npc/cy1guanshi" : 1,
        ]));
                    
        setup();
}




void init()
{
        add_action("do_work", "jiao");
}

int do_work(string arg)
{
        object me;
          int costj, costq;
        me = this_player();
        if (me->query_temp("job4")!=1) return notify_fail("��Ҫ��ʲô��\n");   
        if( !arg && arg !="ˮ") return notify_fail("��Ҫ��ʲô��\n");   
        if (me->is_busy())
                return notify_fail("��������æ�������ء�\n");             
        if( !present("piao", this_player()) ) 
        {  
         	tell_object(me,"\n������ʲô����ˮ��\n");      
                return 1;
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
        {
              message_vision("$N�����������Ҩˮ�����һʧ���Խ��˸��\n",me);
              me->set("water", 350);
              me->unconcious();
              return 1;
        }        
        if(me->query_temp("task")==1)
        {
        	message_vision(RED"�˵ع��¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	return 1;
        }        	        
        if(me->query_temp("jiao")<(10+random(5))) 
        {        
        	message_vision("$N��ư�Ӹ���Ҩ��ˮ���ڲ˵��ｽ��ˮ����\n",me);      	  
        
       		me->receive_damage("jing", costj);
       		me->receive_damage("qi", costq);       
       		me->start_busy(1);
        	me->add_temp("jiao",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"�˵ع��¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	me->set_temp("task",1);        	  
                  me->delete_temp("jiao");
        	return 1;     	
        }
}
