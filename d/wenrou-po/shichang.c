// shichang  ..angle
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "采石场");
        set("long",
"这里是个很大的采石场，可以清楚的看见许许多多的已经采下的大大
小小的岩石垒在山旁，几个采石工人站在巨石上用铁锤敲打着石头，还有
很多的人将石块扛在肩膀上往里面运送。据说这些石头都是用来在山顶上
建造那座"+HIR+"“温柔庵”"+NOR+"所需的，还听说那"+HIR+"“温柔庵”"+NOR+"的掌门师太可是一个世
间罕有的绝色美人！\n ");
        set("no_clean_up", 0);
        set("exits", ([
  "northup" : __DIR__"shanlu1", 
  "west" : __DIR__"shichang1",]));
        set("objects", ([
                __DIR__"songqi" : 1,
        ]));
        set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}


