#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
"�����Ƕ��ҵ�������Ϣ�ĵط����������ڣ�����谵���ְ���������\n"
"���ҵ���˯�����㣬Ҳ�������ڶ���Ů����Ե�����ڶ������൫�����ࡣ\n"
        );                     

        set("exits", ([
		"south" : __DIR__"huayuan1",
               ]));  
        set("sleep_room",1); 
        set("no_fight",1);
        set("coor/x",-50);
	set("coor/y",90);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",90);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",90);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}