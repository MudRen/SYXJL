// Room: lwc.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
������ȫ��̵��ӵ����䳡���㳡�����������˸�ʽ������������е��
�ܶ�ȫ�����������ͷ����������һ��һ�ȵĽ������ϵ�����Ե�ǰ
;���ڵ��Ӷ���ҹ������Ϣ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"guangchang",
 ]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        set("objects", ([
                __DIR__"npc/muren" : 3, 
   ]));
               
        set("coor/x",-100);
	set("coor/y",230);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",230);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",230);
	set("coor/z",190);
	set("coor/x",-100);
	set("coor/y",230);
	set("coor/z",190);
	setup();
        replace_program(ROOM);
}

