inherit ROOM;

void create()
{
	set("short", "���ı����");
	set("long", @LONG
����һ�������Ľֵ������߾��������ǳ�ȥ���������ﳤ����𲻶ϣ�
�������ơ��ϱ���������
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"north" : __DIR__"xisi2",
		"east" : __DIR__"wenmiao",
		"south" : __DIR__"xidan",
	]));
	set("coor/x",-70);
	set("coor/y",180);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}


