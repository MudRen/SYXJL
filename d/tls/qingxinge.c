inherit ROOM;

void create()
{
        set("short", "���ĸ�");
        set("long",@LONG
����������ɮǰȥ��Ժ����֮ǰ���ľ����ĵط�������ֻ�е������
�������ţ�����֮��������ȷȻ�Ǹ��徲֮����
LONG
        );
        set("exits", ([
		"up": __DIR__"qingxinge2",
                "north" : __DIR__"doumugong",
	]));
	set("objects",([
                __DIR__"npc/xiaoshami" : 3,
        ]));
	set("sleep_room", 1);
        set("no_fight",1);
        set("no_steal",1);
        set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-120);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
