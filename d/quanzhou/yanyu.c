// Room: /d/quanzhou/yanyu.c
// Date: May 23, 96   Jay

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����¥�����Ϻ����ĵ�һ��С���ϡ��Ϻ����겻�ϵ�ˮ������
���ֵ��������ɵġ�¥���Ǽҷ��ꡣ
��������װ��¥�ݡ�������¥��
LONG
	);

	set("exits", ([
                "north" : __DIR__ "nanhu1",
	]));

	set("outdoors", "quanzhou");
        set("objects", ([
            __DIR__"npc/xiaoer" : 1]));

	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

