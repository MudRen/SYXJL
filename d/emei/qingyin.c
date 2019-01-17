#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "清音阁");
        set("long",
"清音阁素以“"GRN"双桥清音"NOR"”著称，它背依牛心岭而向五显岭，山峦叠翠，\n"
"阁下有双飞桥，分别飞跨黑龙江和白龙江，稍息亭中，看远山暝暝，听近\n"
"水潺潺，确有一种“起舞弄清影，何似在人间的意境。”\n"
        );

        set("exits", ([
                "southdown" : __DIR__"shenshui",
		"eastup" : __DIR__"wannian",
                "westup" : __DIR__"gate",
               ]));
        set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",90);
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",90);
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",90);
	setup();
        replace_program(ROOM);
}