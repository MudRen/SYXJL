inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ����ʯ·��һ·�����������������ˡ����ϱ��Ƕ��š�
�������������ߡ�
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"northwest" : __DIR__"chaoyang",
		"southeast" : __DIR__"dongmen",
	]));

	set("coor/x",-30);
	set("coor/y",160);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}


