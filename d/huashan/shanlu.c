// shanlu.c

inherit ROOM;

void create()
{
	set("short", "��Ů��ɽ·");
	set("long", @LONG
��������Ů���ɽ��һ��ɽ·��·�߳����˴���ÿ��΢���������
Ҷ��ɳɳ���죬�Ե÷�����ľ���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"yunu",
		"southup" : __DIR__"xiaojing",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x",80);
	set("coor/y",80);
	set("coor/z",70);
	set("coor/x",80);
	set("coor/y",80);
	set("coor/z",70);
	set("coor/x",80);
	set("coor/y",80);
	set("coor/z",70);
	set("coor/x",80);
	set("coor/y",80);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}