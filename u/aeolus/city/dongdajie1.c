// Room: /city/dongdajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
	����һ����������ʯ��ֵ���������ͷ���졣���߲�ʱ�ش�������ײ
�����������������ӡ�������һ�����ӵ�Ժ�ӣ������εĴ����Ϸ�д�š���¹��
Ժ���ĸ��̽���֣��Ծ����������治ʱ�ش���ѧ��������ٴ�Ķ��������ϱ�
��һ���ӻ��̡�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"zahuopu",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"shuyuan",
	]));

	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
