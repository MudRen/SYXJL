// wdroad8.c ����·
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
	������һ����������Ļ���·�ϣ���������ɭɭ�����֡�������һ����ɽ��
LONG
	);
        set("outdoors", "�䵱");

	set("exits", ([
                "north" : "/d/xiangyang/caodi6",
		"west" : __DIR__"shanmen",
		"southwest": "/d/emei/shijie10",
                "east": "/d/wudang/wdroad7",
	]));
	set("objects", ([
		__DIR__"npc/yetu" : 4 ]));

	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

