// Room: /d/shaolin/zhonglou2.c



inherit ROOM;









void create()

{

	set("short", "��¥����");

	set("long", @LONG

ÿ��¥���϶������˽�ʵ��ľ¥�壬�˽��ε�ǽ������

�����ȴ󴰡��Ӵ��׿���ǽ��Ҳ�Ǽ�Ϊ��ʵ������������������

���Կ���Χ�����ܵ�С԰�Լ����ߵ����֣����Ʈ��������Ҷ

�����㡣

LONG

	);



	set("exits", ([

		"up" : __DIR__"zhonglou3",

		"down" : __DIR__"zhonglou1",

	]));



	setup();

	replace_program(ROOM);

}






