#include <ansi.h>



inherit ROOM;



void create()

{

    set("short", "���");

    set("long", @LONG

����һ�����Ĵ����ȫ����ʯ�ѳ�,��Ȼ�����˲�������.

������һ�����������䳡,������һƬ������.

LONG

    );



    set("exits", ([

		"east" : __DIR__"wuchang",

		"west" : __DIR__"kongdi",

    ]));

    set("objects", ([

		"/d/shenlong/npc/xuxuetin": 1,

    ]));

        set("no_beg",1);
        set("no_yun",1);
        set("no_fight",1);
        set("no_setal",1);
    set("outdoors", "shenlong");

    setup();

   replace_program(ROOM); 

}





