// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "��ϼ��");
	set("long", @LONG
����һ����ʷ�ƾö���ΰ׳������Ժ���ഫ�����ƴ���ǰ����
��Ԫ�����������������������Ժ���ж�������ֱ��Ϊ������
�⣬�����Ž���͵ľ�ʩ����������߶����������ɡ����ķ�����
��̩ɽ�������Ů�������ȵ���ϼ����Ȼ��ŵ��������������
���������߱�ɵ��ﱦ���롣
LONG
	);

	set("exits", ([
		"west" : __DIR__"weipin",
		"eastdown" : __DIR__"baozang",
	]));

	set("outdoors", "taishan");
	set("coor/x",100);
	set("coor/y",120);
	set("coor/z",120);
	set("coor/x",100);
	set("coor/y",120);
	set("coor/z",120);
	set("coor/x",100);
	set("coor/y",120);
	set("coor/z",120);
	set("coor/x",100);
	set("coor/y",120);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}

