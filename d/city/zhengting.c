// Room: /city/zhengting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	�����Ǹ����ھֵ���������ֻ̫ʦ��һ���ſ�����������������ͷ���ֳ�
�̴������ڱ�Ŀ��˼��ǽ�Ϲ��ż����ֻ���һ�ѱ�����
LONG
	);

	set("exits", ([
		"north" : __DIR__"biaoju",
	]));

	set("objects", ([
                     __DIR__"npc/linzhennan" : 1,
	]));

        set("no_fight",1);
        set("no_sleep_room",1);
        set("no_yun",1);
        set("no_steal",1);
        set("no_beg", 1);
	setup();
	replace_program(ROOM);
}

