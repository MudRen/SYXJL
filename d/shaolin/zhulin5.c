// Room: /d/shaolin/zhulin5.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ������������
�ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ������
΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ���
���������ڡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"hsyuan5",
		"south" : __DIR__"zhulin4",
		"west" : __DIR__"cjlou",
		"north" : __DIR__"zhulin6",
	]));

	set("outdoors", "shaolin");
	set("coor/x",-20);
	set("coor/y",340);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}


