// tyroad2.c ʯ��
// by Marz 

inherit ROOM;

void create()
{
	set("short", "���ҷ�");
	set("long", @LONG
	����һ������ʵ��ʯ��·����ʱ���н���ͺ����˴��������߹���̧ͷ������
��ΰ��������������������֮�У�Ρ��׳�ۣ�����һ��ʯ��ͨ��ɽ�£���Լ�ɼ�Զ��
�һ�ƬƬ��������Ŀ��
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"lameigt",
		"east" : __DIR__"tyroadct",
		"northup" : __DIR__"wuyalin",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
		
	set("coor/x",-70);
	set("coor/y",100);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",100);
	set("coor/z",190);
	set("coor/x",-70);
	set("coor/y",100);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}

