// xiaolu1.c �ּ�С��
// by Xiang

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
	������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ�����
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaolu2",
		"south" : __DIR__"zijincheng",
	]));
	set("coor/x",-70);
	set("coor/y",190);
	set("coor/z",230);
	set("coor/x",-70);
	set("coor/y",190);
	set("coor/z",230);
	set("coor/x",-70);
	set("coor/y",190);
	set("coor/z",230);
	setup();
	replace_program(ROOM);
}

