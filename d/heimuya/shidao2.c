inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ·�����½̽��ڰ������ܣ���������ɽ��������һ��ˮ̲֮ǰ������
��һ��ʯ��ͨ��ˮ̲��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
		"westdown" : __DIR__"xingxingtan",
//		"east" : __DIR__"liangting",
		"south" : __DIR__"shidao",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shashou.c" : 2,
  __DIR__"npc/wang" : 1,
]));

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
