// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "Χ��ɽ");
	set("long", @LONG
������̩ɽ������һ��ɽ�塣ɽ�Ķ�����һ����ͷ�£�����״
����һͷ�����������бܷ��£����ϴ��ؿ��š����¸ԡ�������
���档�������б���̳�������������ߣ���ɵ����ŷ�̩ɽ֮���
ϼԪ���ı�ϼ����
LONG
	);

	set("exits", ([
		"westdown" : __DIR__"tianjie",
                 "north" : __DIR__"beitian",
		"east" : __DIR__"bixia",
	]));

	set("outdoors", "taishan");
	set("coor/x",90);
	set("coor/y",120);
	set("coor/z",120);
	set("coor/x",90);
	set("coor/y",120);
	set("coor/z",120);
	set("coor/x",90);
	set("coor/y",120);
	set("coor/z",120);
	set("coor/x",90);
	set("coor/y",120);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}

