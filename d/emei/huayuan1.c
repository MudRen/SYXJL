#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long",
"�Ӻ�Ժ�����߾͵����������һ����԰�������˸����滨��ݡ�\n"
"���ܾ��ǵ����ǵ��޷��ˣ�������Ȼ�е��Ӳ��Ͻ��������������Ǻܰ�����\n"
        );

        set("exits", ([
		"north" : __DIR__"room1",
                "south" : __DIR__"room3",
		"east" : __DIR__"houyuan",
		"west" : __DIR__"room2",
               ]));
        set("coor/x",-50);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",80);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}