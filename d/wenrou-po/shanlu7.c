// shanlu7  ..angle
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIR"温柔庵"NOR);
        set("long", 
"这是一座刚刚开始修建的尼姑庵，可以看出已经初具规模。单檐歇山
式布瓦顶的结构，所有的木构件都是用精选上好的楠木制成，石构件则是由
山下的采石场采集而来。巨大的横梁上龙飞凤舞的写着"+HIR+"温柔庵"+NOR+"几个大字，
甚是夺目！\n");
        set("no_clean_up", 0); 
        set("no_fight", 1);
        set("no_steal", 1);
         set("exits", ([
  "southdown" : __DIR__"shanlu6",])); 
        set("objects", ([
                __DIR__"npc/shitai" : 1,
                __DIR__"npc/xiao-nigu" : 2,
        ]));        set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",70);
	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",70);
	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",70);
	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",70);
	setup();
}


