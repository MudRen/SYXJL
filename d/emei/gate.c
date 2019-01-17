#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "千佛庵大门");
        set("long",
"这里就是峨嵋山上最著名的庵----千佛庵的大门，再往北沿石阶向上\n"
"就是千佛庵了。大门外有一片小场子，一些峨嵋派收养的孤儿在此玩耍。\n"
"还有一些山上的居民为了生计在此叫卖。\n"
        );

        set("exits", ([
		"northup" : __DIR__"dian1",
		"eastdown" : __DIR__"qingyin",
               ]));  
        set("objects",([
              __DIR__"npc/girl1" : 3, 
              __DIR__"npc/xiao-fan" : 1,
             ]));
        set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",100);
	setup();
        replace_program(ROOM);
}