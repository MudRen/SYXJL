// Room: /d/tianlongsi/gulou3.c



inherit ROOM;









void create()

{

	set("short", "��¥����");

	set("long", @LONG

���������ƺ�Խ��Խխ��¥��Ҳ��Ϊ���ơ������ϲ�����

������������ľ����ɫҲ���¾ɲ�ͬ���Ӵ�����������������

�Կ��������еĲؾ�¥�ͷ���¥¶������һ�ǣ��������Ǻ��

���ݶ����ݼ������˸����ġ����֡�

LONG

	);



	set("exits", ([

		"up" : __DIR__"gulou4",

		"down" : __DIR__"gulou2",

	]));



	setup();

	replace_program(ROOM);

}







