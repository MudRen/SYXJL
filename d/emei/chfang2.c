#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
"�����Ǿ���ʦ̫���������򵥶�����İڷ���һ�Ŵ���һ��С��������\n"
"���ż����𾭣�����ʦ̫�������ڴ��ϣ�һ������ľ��һ�����\n"
        );

        set("exits", ([
		"west" : __DIR__"xilang1",
               ]));  
        set("objects",([
            __DIR__"npc/jingxian" : 1,
               ]));  

        set("coor/x",-50);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",20);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}