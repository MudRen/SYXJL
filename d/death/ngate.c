// gate.c 鬼门关
// writed by shadow

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "鬼门关" NOR );
        set("long",
"这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的黑\n"
"色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再回阳\n"
"间了。\n");
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
