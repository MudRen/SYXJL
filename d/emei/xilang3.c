#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
"������ǧ�������ߵĹ����������Ϻܰ�������ʱ���������������ߴ�\n"
"����ľ�������̾����������Ǿ���ʦ̫�������������Ǿ���ʦ̫��������\n"
        );

        set("exits", ([
		"north" : __DIR__"xilang4",
                "south" : __DIR__"xilang",
		"east" : __DIR__"chfang6",
		"west" : __DIR__"chfang5",
               ]));
        set("coor/x",-60);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",50);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}