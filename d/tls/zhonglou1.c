// Room: /d/tianlongsi/zhonglou2.c



inherit ROOM;









void create()

{

	set("short", "��¥һ��");

	set("long", @LONG

ÿ��¥���϶������˽�ʵ��ľ¥�壬�˽��ε�ǽ������

�����ȴ󴰡��Ӵ��׿���ǽ��Ҳ�Ǽ�Ϊ��ʵ������������������

���Կ���Χ�����ܵ�С԰�Լ����ߵ����֣����Ʈ��������Ҷ

�����㡣

LONG

	);



	set("exits", ([

		"up" : __DIR__"zhonglou2",

		"out" : __DIR__"zhonglou",

	]));



	setup();

	replace_program(ROOM);

}







