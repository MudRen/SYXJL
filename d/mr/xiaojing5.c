#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ������������������濴ȥ��һ
Ƭ�����֣�������һ�����ȡ�������С�������졣
long);
set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaojing6",
             "north" : __DIR__"liulin",
             "west" : __DIR__"shiqiao1",
             "south" : __DIR__"cl2",
]));
        set("coor/x",110);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
