//chashi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ��������Ϳ����ŵ�һ�ɲ�Ҷ�����㣬ǽ���и���ˮ��С¯������
��ˮ���Ѿ���ʼ���⡰˻˻����ðˮ���ˡ������ϵ�����������ط�
�ż�����Ư���ĵ񻨲��ѡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaoxuan",
		]));
	set("objects", ([
		  __DIR__"obj/xiangcha" : 2,
	]));


	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}