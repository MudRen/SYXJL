// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����λ��ʯ��ɽ�ı�´����᷶��ı�����ڣ�·����һʯ����
����д�š����䡹���֡�
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"zhangren",
	]));

	set("outdoors", "taishan");
	set("coor/x",60);
	set("coor/y",140);
	set("coor/z",120);
	set("coor/x",60);
	set("coor/y",140);
	set("coor/z",120);
	set("coor/x",60);
	set("coor/y",140);
	set("coor/z",120);
	set("coor/x",60);
	set("coor/y",140);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}

