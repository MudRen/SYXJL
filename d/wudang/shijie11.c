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
		"eastdown" : __DIR__"shanmen",
		"northup" : __DIR__"shijie12",
	]));
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

