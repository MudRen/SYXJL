inherit ROOM;

void create()
{
        set("short", "���ĸ��¥");
        set("long",@LONG
����������ɮǰȥ��Ժ����֮ǰ���ľ����ĵط�������ֻ�е������
�������ţ�����֮��������ȷȻ�Ǹ��徲֮����
LONG
        );
        set("exits", ([
		"down": __DIR__"qingxinge",
            ]));
	set("sleep_room", 1);
        set("no_fight",1);
        set("no_steal",1);
        set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",40);
	set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",40);
	set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",40);
	set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
