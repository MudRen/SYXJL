
inherit ROOM;

void create()
{
	set("short", "���ݳ�");
	set("long", @LONG
���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ
���ر����̲��������������ˣ����������𸽽�ɽ�ϵĲݿܡ���
��һ�Ӷӹٱ�����ȥȥ��һ��ɭ���������������Ǳ��Ͼ��ǵ�
�ؾ�֮�����ٱ��̲�Ҳʮ���ϸ񡣴������۶���������������֮
һ����ɽ�ˡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"yidao3",
		"north" : "/d/city2/road10",
		"west" : __DIR__"shijie1",
		"east" : __DIR__"marry_room",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",140);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}



