// Room: /d/tianlongsi/gulou2.c





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

		"up" : __DIR__"gulou3",

		"down" : __DIR__"gulou1",

	]));



	setup();

	replace_program(ROOM);

}







