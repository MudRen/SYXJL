// Room: /d/emei/dian2.c ������ �����

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",
"������ǧ���ֵ�ǰ��----����������¬��͵������������\n"
"��������ǧ���ֵĴ���ˡ�������Ϲ������������������������һ��\n"
"���׶�ߵ��������������߸���һ����������������һЩ���š��տ��⡣\n"
"����Ǿ���ʦ̫��\n"
        );

        set("exits", ([
                "south" : __DIR__"dian1",
		"north" : __DIR__"dadian",
               ])); 
        set("objects", ([
            __DIR__"npc/jingfeng" : 1,
              ]));

        set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}