#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西侧门");
        set("long",
"这里是千佛庵的西侧门了，这是一个月亮门，不时有峨嵋弟子们来来往\n"
"往。出西侧门后一条小道展现在你眼前，沿小道走就到了弟子们练功的草坪。\n"
        );

        set("exits", ([
		"east" : __DIR__"xilang",
		"west" : __DIR__"xiaodao",
               ]));
        set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}