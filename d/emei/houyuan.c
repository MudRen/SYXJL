#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long",
"������ǧ���ֵĺ�԰������һ����Ϊ�����Ĵ�Ժ�ӣ��������߸���һ\n"
"��ͥԺ�����ߵ�ͥԺ�ǵ����ǵ��޷������ߵ�ͥԺ���׼ҵ��ӵ��޷���\n"
        );

        set("exits", ([
		"north" : __DIR__"houmen",
                "south" : __DIR__"shendeng",
		"west" : __DIR__"huayuan1",
               ]));
        set("coor/x",-40);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",80);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}
