//TOHSQ4.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ɽ·�������ƺ���ÿ�����Щ�����µ�ɽ���������������
�����Ϊһˬ��Զ����������ˮ�������н�Զ��ɽ���Ϲ���
�˺��ܵ����ܣ��������ҡ߮��
LONG
	);

	set("exits", ([
		"north" : __DIR__"tohsq5",
		"south" : __DIR__"tohsq2",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-140);
	set("coor/y",20);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}