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
		"southdown" : __DIR__"shijie61",
		"northup" : __DIR__"guangchang",
	]));
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",170);
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",170);
	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",170);
	setup();
	replace_program(ROOM);
}

