#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С��");
        set("long",
"���������������С�������������ź����������Ĳ�ƺ����ʱ��СŮ\n"
"����С�������������\n"
        );

        set("exits", ([
		"northup" : __DIR__"taizi",
		"east" : __DIR__"xicemen",
		"southwest" : __DIR__"leidong",
               ]));
        set("coor/x",-80);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-80);
	set("coor/y",40);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}