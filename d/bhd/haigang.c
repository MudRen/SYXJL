
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���޼ʵĴ󺣣�����������ԼԼ�ܿ�����һ�Ҵ���
����������Լ�������������������������ĳ�ˮ����������
�����𵺵�Ψһ��·�ˡ�
LONG
	);

	set("exits", ([
                "west" : "/d/city2/road3",
	]));

	set("objects", ([
		__DIR__"npc/chuanfu" :1,
	]));

	set("outdoors", "city2");
	set("coor/x",20);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
