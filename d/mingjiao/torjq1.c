//TORJQ1.C

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������ͨ�������Ĵ������·��������ſ���ʮ�˲�����С�
�ഫ����������������г������磬��ģ��Ϊ��ΰ�ġ��������˲�
�����������ػ�������Χ�����������������б����ͻ��ߵĴ��졣
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"torjq2",
		"southwest" :__DIR__"lhqpaifang",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-140);
	set("coor/y",-30);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}