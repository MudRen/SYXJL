// Room: /d/quanzhou/haigang.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǳ����ıؾ�֮�أ���������Գ������һ�����Ŀǰ����ʩ���С�
LONG
	);

	set("exits", ([
                "west" : __DIR__"zhongxin",
                "south" : __DIR__"yucun",
	]));

	set("objects", ([
                __DIR__"npc/boy":2,
                __DIR__"npc/girl":1,
	]));

        set("outdoors", "Ȫ��");
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

