// shijie1.c ʯ��
// by Xiang

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
	������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ������
�ڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ���ȣ�������
��������
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"yuzheng",
		"northup" : __DIR__"shijie22",
	]));
	set("coor/x",-50);
	set("coor/y",-60);
	set("coor/z",40);
	set("coor/x",-50);
	set("coor/y",-60);
	set("coor/z",40);
	set("coor/x",-50);
	set("coor/y",-60);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}

