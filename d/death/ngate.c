// gate.c ���Ź�
// writed by shadow

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "���Ź�" NOR );
        set("long",
"�������������������ڡ����Źء���������ǰ������һ���ߴ�ĺ�\n"
"ɫ��¥������������޿�������ж�ǰ������Ϊһ�����Źؾ��޷��ٻ���\n"
"���ˡ�\n");
	set("no_fight",1);

	set("exits", ([
		"north" : "/d/death/gateway",
	]));
	set("no_dun",1);
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );

        setup();
        replace_program(ROOM);
}

void init()
{ 
        object ob;
        ob = this_player();
        //::init();     
        add_action("do_action", "");                             
}



int do_action(string arg)
{
       string action = query_verb();

       switch (action) { 
 
               case "dazuo": 
               case "get":                
               case "lian":
               case "tuna":       
               case "dazuo" : 
                       return 1;
      }
      return 0;
}
