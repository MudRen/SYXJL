inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
��������������֡�������һ�Һܴ�Ķĳ��������ֺ��ġ�
���������ı���֡��ϱ߾��������ˡ�
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"north" : __DIR__"xisi",
		"south" : __DIR__"xidan",
		"east" : __DIR__"duchang",
	]));
	set("objects", ([
	"/d/taishan/npc/seng-ren" : 1,
	]));


	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}


