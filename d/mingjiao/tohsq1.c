//TOHSQ1.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ������ͨ��ɽ·��·�ߵ������ܼ����������㣬�ݴ�
�����ǵ��ص�׺��һЩ��ɫҰ����һ����Ȫ�������˵���ɽ����
�ʣ�Զ����������ˮ����Ϊ��ɽ�ȶ����˼������ơ�
LONG
	);

	set("exits", ([
//		"west" : __DIR__"rjqmen",
		"southeast" :__DIR__"torjq3",
		"northwest" :__DIR__"tohsq2",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-130);
	set("coor/y",0);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}