
inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����һ�����䳡,�ɾ޴�Ļ�����ʯ���̾�,�����ż���ľ�ˡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"kang2",
	]));

	set("objects",([
                "/d/shaolin/npc/mu-ren" : 4 ]));

	set("outdoors", "city2");
	set("coor/x",-50);
	set("coor/y",200);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
