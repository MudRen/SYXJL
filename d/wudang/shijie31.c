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
		"southdown" : __DIR__"bolin",
		"northup" : __DIR__"shijie32",
	]));
	set("coor/x",-50);
	set("coor/y",-30);
	set("coor/z",70);
	set("coor/x",-50);
	set("coor/y",-30);
	set("coor/z",70);
	set("coor/x",-50);
	set("coor/y",-30);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}

