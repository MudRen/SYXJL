// cave2.c

// by QingP



inherit ROOM;



void create()

{

	set("short", "ɽ��");

	set("long", @LONG

����һ��ʮ�ֿ���ɽ��������ʯ���ϵ�����յ�谵���͵ơ��������޵ĵ�����

�����������Ȼ���ֵ��Ͼ�Ȼ�ɼ���֫�彩Ӳ����Ŀ�Ұ׵���ʬ��

LONG

	);



	set("exits", ([

		"out" : __DIR__"xxh8",

	]));



	set("objects",([

		__DIR__"npc/kuilei" : 4,

	]));

	

	setup();



}