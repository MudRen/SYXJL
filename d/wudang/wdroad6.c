// wdroad6.c ����·
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
	������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǻ������磬
��˵���������˳�û�����ɾ������������ߣ����ǽ䱸���ϵ��������ˡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northeast" : __DIR__"wdroad5",
                "west" : "/d/xiangyang/eastgate2",
	]));

	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

