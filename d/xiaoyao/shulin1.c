// shulin1.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ���������졣
LONG
        );

       set("exits", ([
               "north" : __DIR__"shulin1",
               "south" : __DIR__"shulin1",
               "east" : __DIR__"shulin2",
               "west" : __DIR__"xiaodao4",
       ]));
	set("outdoors", "xiaoyao");
	set("objects", ([
//		__DIR__"npc/shuxingh": 1,
//		__DIR__"npc/xue": 1,
]));
	set("no_clean_up", 0);
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}