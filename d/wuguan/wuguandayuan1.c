// Room: /d/wuguan/wuguandayuan1.c
// Date: 99/05/30 by Byt
#include <ansi.h>
inherit ROOM;
int potential_lv(int exp);
void create()
{
        set("short", "武馆大院");
        set("long", @LONG
这是个大院子，东西两边都是练武场，不少人在这里习武强身，这里
很吵，乱烘烘的，你看见不时有扛着东西的，挑着水的匆匆而过，北面上
了台阶就是武馆大厅。
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
        if(me->query_temp("toyed")==1) return notify_fail("张风说道：你得先归还工具才行。\n"); 
        if (me->query_temp("tasked")!=1) return notify_fail("什么？\n"); 
        if( !arg && arg !="ok") return notify_fail("什么？\n");           
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
        if(me->query("gender")=="男性")
                message_vision(CYN"张风说道：好，小兄弟，做得好，这是给你的奖赏！\n"NOR,me);        
        else    
        	message_vision(CYN"张风说道：好，小姑娘，做得好，这是给你的奖赏！\n"NOR,me);
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


