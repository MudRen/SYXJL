// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������̩ɽ��һ����ʤ��������һ��״��ʨ�ӵľ�ʯ����Ϊʨ
���¡�������Ļ���Ҫ���ڶ�����Ķ�������Ҳ�����������ǹŴ�
�����ĵط���������һ�������ڵļ�̩ɽ����
LONG
	);

	set("exits", ([
		"westup" : __DIR__"weipin",
	]));

	set("outdoors", "taishan");
	set("coor/x",110);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",110);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",110);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",110);
	set("coor/y",120);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
