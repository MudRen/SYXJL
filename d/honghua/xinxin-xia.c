//Room /d/honghua/xinxin-xia.c
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","星星峡");
	set("long",@LONG
你眼前几块石壁一字排开，直伸出去，山石间云雾弥漫，似乎
其中别有天地，再奔近时，忽觉峭壁中间露出一条缝来，那便是甘
肃和回疆之间的交通要道星星峡
LONG
	);
	
	set("outdoor", "honghua");	

        set("objects", ([
                "/u/ybl/honghua/npc/yuyutong" : 1,
                "/u/ybl/honghua/npc/qingtong" : 1,
        ]));    


	set("exits", ([
		"south" : __DIR__"shanxia",
		"north" : __DIR__"caoyuan3",
	]));

	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",0);
	setup();
}
