
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
		"north" : __DIR__"xilang2",
		"east" : __DIR__"chfang2",
		"west" : __DIR__"chfang1",
               ]));
        set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}