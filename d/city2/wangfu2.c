

inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�ϱ߱��߶��ǳ�����
�ֵ��������������ġ�ȫ�۵¡���¥������ͨ�������š�
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"west" : __DIR__"jiulou1",
		"south" : __DIR__"wangfu1",
		"east" : __DIR__"chaoyan1",
		"north" : __DIR__"wangfu3",
	]));
	set("objects", ([
		"/d/city2/npc/flowerg": 2,
	]));

	set("coor/x",-60);
	set("coor/y",170);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

