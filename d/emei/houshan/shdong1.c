inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ�������ٲ������ɽ���������ٲ����΢����Կ���ɽ���Ĵ����
��������һ���ܴ����Ȼ��Ѩ�������г����ź�Ũ�����ζ������������һ��
�ڶ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"pubu",
  "east" : __DIR__"shdong2",
]));
	setup();
	replace_program(ROOM);
}
