// Room: /d/wuguan/wuguandayuan1.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
int potential_lv(int exp);
void create()
{
        set("short", "��ݴ�Ժ");
        set("long", @LONG
���Ǹ���Ժ�ӣ��������߶������䳡��������������ϰ��ǿ������
�ܳ����Һ��ģ��㿴����ʱ�п��Ŷ����ģ�����ˮ�ĴҴҶ�����������
��̨�׾�����ݴ�����
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"wuguandayuan",
                "north"  : __DIR__"wuguandating",
        ]));
      	set("objects", ([
                __DIR__"npc/zhangfeng" : 1,
        ]));        
        setup();
}

void init()
{
          add_action("do_job", "task");
}

int do_job(string arg)
{
	object me = this_player();
	object ob;
	int bonus;
        if(me->query_temp("toyed")==1) return notify_fail("�ŷ�˵��������ȹ黹���߲��С�\n"); 
        if (me->query_temp("tasked")!=1) return notify_fail("ʲô��\n"); 
        if( !arg && arg !="ok") return notify_fail("ʲô��\n");           
        bonus = (int)me->query("potential");
        bonus = bonus - (int)me->query("learned_points");
        bonus = bonus + random(3) +4;
        if ( bonus > potential_lv((int)me->query("combat_exp")) )
        bonus = potential_lv((int)me->query("combat_exp"));
        bonus += (int)me->query("learned_points");
        me->set("potential", bonus );
        me->add("combat_exp",60);
	ob = new("/clone/money/silver");
	ob->move(this_player());        
        if(me->query("gender")=="����")
                message_vision(CYN"�ŷ�˵�����ã�С�ֵܣ����úã����Ǹ���Ľ��ͣ�\n"NOR,me);        
        else    
        	message_vision(CYN"�ŷ�˵�����ã�С������úã����Ǹ���Ľ��ͣ�\n"NOR,me);
        me->delete_temp("tasked");
        me->delete_temp("task");        
        return 1;
}



int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;
        return grade;
} 


