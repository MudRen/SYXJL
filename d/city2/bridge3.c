

inherit ROOM;

void create()
{
	set("short", "�ŵ׶���");
	set("long", @LONG
������С�����࣬һ�ɺ��紵���������ɪɪ������ֻ���뿪��
LONG
	);
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"bridge",
	]));
        set("coor/x",-40);
	set("coor/y",160);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

