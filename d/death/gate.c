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
int heal_up(object who)
{
        who->set("eff_qi", (int)who->query("max_qi"));
        who->set("eff_jing", (int)who->query("max_jing"));

   message_vision("忽然一股青气笼住了$N。\n", who);
   write("你觉得自己的精神气血一下子都恢复了。\n");

   return 1;
}

