// Room: shiliang.c ʯ��
// arnzh 97/1/24
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
	    ����һ����ͺͺ��ʯ��,�����ƺ����˶�վ����,�����кü�ֻ���ӣ�
�����������Ϸ��ʱ��ɧ�����ˡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"xiaolu4",
	]));

	set("objects", ([
		__DIR__"npc/monkey" : 3,
	]));

	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",120);
	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",120);
	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}

