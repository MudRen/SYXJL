
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
		"north" : __DIR__"xilang5",
                "south" : __DIR__"xilang3",
		"east" : __DIR__"chfang8",
		"west" : __DIR__"chfang7",
               ]));
        set("coor/x",-60);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",60);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",60);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}