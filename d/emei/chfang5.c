#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
"�����Ǿ���ʦ̫���������򵥶�����İڷ���һ�Ŵ���һ������ľ��һ�����\n"
"���ż����𾭣�����ʦ̫�������ڴ��ϣ�һ������ľ��һ�����\n"
       );

        set("exits", ([
		"east" : __DIR__"xilang3",
               ]));  
        set("objects", ([
          __DIR__"npc/jingxu" : 1,
             ]));
        set("coor/x",-70);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",50);
	set("coor/z",110);
	set("coor/x",-70);
	set("coor/y",50);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}