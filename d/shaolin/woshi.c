// Room: /d/shaolin/woshi.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "����");
	set("long", @LONG
�Է���ֻ��һ�����Ƶİ����������˰����õ���ϯ��ϯ���ϵ�
һ�����������ϡ�ϯ�ȱ���һ�Ѷ��˵ĵ��������ϰ߰ߵ���ƺ���
�ö���ǰ���µ�Ѫ����
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaowu",
	]));

	set("coor/x",-30);
	set("coor/y",170);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}


