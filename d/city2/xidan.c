inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������������������ʮ�����֡�������Ȼ�࣬����ֻ�Ĵ�����,
�Ŷ������������Ҳ��������ʲô�������м��ӻ��̣�ȥ�����������˺ܶࡣ
�������˴ӱ����������ƺ�����Ҳͦ���֡��ϱ����������֡�
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
		"west" : __DIR__"zahuopu",
		"south" : __DIR__"xichang2",
		"north" : __DIR__"xidan1",
	]));
	set("objects", ([
	    "/d/city2/npc/xiaofan": 1,
	    "/d/huashan/npc/youke": 2,
	]));

	set("coor/x",-70);
	set("coor/y",160);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}


