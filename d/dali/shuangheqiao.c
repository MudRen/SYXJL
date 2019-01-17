//Room: /d/dali/shuangheqiao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","双鹤桥");
        set("long",@LONG
这是一个岔路口，北边是座青石拱桥名叫双鹤桥，此桥跨在绿玉
溪上，桥北即是大理城，由此南去是通往南方的喜州、龙口等城镇的
官道。
LONG);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 3 */
            "north"     : __DIR__"southgate",
            "west"      : __DIR__"luyuxi",
            "south"     : __DIR__"road4",
        ]));
        set("no_clean_up", 0);
        set("coor/x",-10);
	set("coor/y",-150);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-150);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-150);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-150);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
