

inherit ROOM;

void create()
{
	set("short", "�ŵ�����");
	set("long", @LONG
������С�����࣬һ�ɺ��紵���������ɪɪ������ֻ���뿪��
LONG
	);

	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"bridge",
	]));
        set("coor/x",-60);
	set("coor/y",160);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

