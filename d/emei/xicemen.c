#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
"������ǧ���ֵ��������ˣ�����һ�������ţ���ʱ�ж��ҵ�����������\n"
"�����������ź�һ��С��չ��������ǰ����С���߾͵��˵����������Ĳ�ƺ��\n"
        );

        set("exits", ([
		"east" : __DIR__"xilang",
		"west" : __DIR__"xiaodao",
               ]));
        set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}