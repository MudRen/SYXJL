//TOHSQ2.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ƺܶ��ͣ�����һ��������ʮ���ɽ�ȣ������ߣ���
��ȥ��������췽���·��·���Է����Ӱ��ɽ����������һ��Ұ
�ط�⡣�������Ǵ����������֮�У������˲������ܵ�һ����
ɪ�ĺ��⡣
LONG
	);

	set("exits", ([
//		"west" : __DIR__"rjqmen",
		"southeast" :__DIR__"tohsq1",
		"northwest" :__DIR__"tohsq3",
		"north" : __DIR__"tohsq4",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-140);
	set("coor/y",10);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}