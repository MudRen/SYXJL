// Room: /d/wuguan/caiang.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��");
        set("long", @LONG
������ﶣ�����ѵģ�����ϸһ����������������������ر��
����һ�߶������Ѿ���̵�ľͷ��������һ�����õĲ��ȴû�ж��١�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "west" : __DIR__"houyuan",
        ]));
        set("objects", ([
                __DIR__"npc/cfguanshi" : 1,
        ]));
        setup();
}



void init()
{
        add_action("do_work", "pi");
}

int do_work(string arg)
{
        object me;
        int costj, costq;
        me = this_player();
        if (me->query_temp("job3")!=1) return notify_fail("��Ҫ��ʲô��\n");   
        if( !arg && arg !="��") return notify_fail("��Ҫ��ʲô��\n");   
        if (me->is_busy())
                return notify_fail("��������æ�������ء�\n");             
        if( !present("chaidao", this_player()) ) 
        {  
         	tell_object(me,"\n������ʲô��������������\n");      
                return 1;
        }

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
                message_vision("$N��һ�ᣬ��С�������Լ�������\n",me);
                me->receive_wound("qi", 20);
                me->set_temp("last_damage_from", "��С�ı��Լ���");
                me->unconcious();
                return 1;
                }
        if(me->query_temp("task")==1)
        {
        	message_vision(RED"�񷿹��¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	return 1;
        }        	        
        if(me->query_temp("pi")<(10+random(5))) 
        {        
        	message_vision("$N����һ��ľͷ��һ��������ȥ�����ѡ���һ����ľͷ����Ϊ��Ƭ��\n",me);      	  
        
        	me->receive_damage("jing", costj);
       		me->receive_damage("qi", costq);   
       		me->start_busy(1);

        	if ( (int)me->query_skill("blade", 1) < 20 && random(10)>5 )
        	{  
                	write(HIM"���������ж��ڵ����÷���Щ���!\n"NOR);
                	me->improve_skill("blade", (int)(me->query("str") / 10));
                }       		
        	me->add_temp("pi",1);       	
       		return 1;
       	}
        else 
        {
        	message_vision(RED"�񷿹��¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR,me);
        	me->set_temp("task",1);
                  me->delete_temp("pi");
        	return 1;     	
        }
}
