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
		"southdown" : __DIR__"xiaochidian",
		"northup" : __DIR__"shibapan",
	]));
	set("coor/x",-50);
	set("coor/y",30);
	set("coor/z",130);
	set("coor/x",-50);
	set("coor/y",30);
	set("coor/z",130);
	set("coor/x",-50);
	set("coor/y",30);
	set("coor/z",130);
	setup();
	replace_program(ROOM);
}

