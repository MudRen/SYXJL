#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "神水阁");
        set("long",
"这里是峨眉派封山断道的所在，左面的岩石上刻着几个大字“"HIW"大峨"NOR"”\n"
"比划深入岩壁，好象是绝顶高手以内家指力书就，令人不由峤舌，路旁有\n"
"一个禅院，门前站着几个尼姑，手持长剑，似乎在盘查着经过的人，此地不宜\n"
"久留，还是快走吧。\n"
        );

        set("exits", ([
                "southdown" : __DIR__"shijie2",
		"northup" : __DIR__"qingyin",        
               ]));
         set("objects",([
//           __DIR__"npc/xiaofan2" : 1,
            ]));
        set("no_fight",1);
        set("no_yun",1);
        set("no_beg",1);
        set("no_setal",1);
        set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",80);
	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",80);
	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",80);
	setup();
        replace_program(ROOM);
}
