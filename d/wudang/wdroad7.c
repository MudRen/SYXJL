// wdroad7.c ����·
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
	������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǻ������磬
��˵���������˳�û�����ɾ�����
LONG
	);
        set("outdoors", "�䵱");

	set("no_sleep_room",1);

	set("exits", ([
		"west" : __DIR__"wdroad8",
		"southup" : __DIR__"tufeiwo1",
	]));

	set("coor/x",-20);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

