#include <ansi.h>
 
inherit ROOM;

void create()
{
	set("short", RED"解剑石"NOR);
	set("long",
"这里是峨眉山脚下著名的"RED"解剑石"NOR"。在石阶的旁边立着一块巨大的石\n"
"块，上面锩刻着"RED"“解剑石”"NOR"三个大字。"RED"解剑石"NOR"的旁边站着几个峨嵋女\n"
"弟子在检查过往行人。\n"
         );
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie1",
  "northup" : __DIR__"gchang",
           ]));

        set("objects",([
            __DIR__"npc/shoushan" : 2,
               ])); 	

	set("coor/x",-60);
	set("coor/y",-70);
	set("coor/z",10);
	set("coor/x",-60);
	set("coor/y",-70);
	set("coor/z",10);
	set("coor/x",-60);
	set("coor/y",-70);
	set("coor/z",10);
	setup();
}

int valid_leave(object me, string dir)
{
        
        if ((me->query_temp("weapon") || me->query_temp("secondary_weapon"))
             && objectp(present("shoushan dizi", environment(me))) && 
              dir == "northup" && (string)me->query("family/family_name") != "峨嵋派")
                return notify_fail("守山弟子说: 峨嵋非行凶之地，施主想要上山请解兵器。\n");
        return ::valid_leave(me, dir);
}