#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ǧ���ִ���");
        set("long",
"������Ƕ���ɽ������������----ǧ���ֵĴ��ţ���������ʯ������\n"
"����ǧ�����ˡ���������һƬС���ӣ�һЩ�����������Ĺ¶��ڴ���ˣ��\n"
"����һЩɽ�ϵľ���Ϊ�������ڴ˽�����\n"
        );

        set("exits", ([
		"northup" : __DIR__"dian1",
		"eastdown" : __DIR__"qingyin",
               ]));  
        set("objects",([
              __DIR__"npc/girl1" : 3, 
              __DIR__"npc/xiao-fan" : 1,
             ]));
        set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",100);
	setup();
        replace_program(ROOM);
}