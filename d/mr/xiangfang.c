#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","�᷿");
         set ("long",@long
����һ���᷿, ��������, ֻ��һ�Ŵ�, һ��������һ�����ӡ�
long);
         set("no_fight", 1);
         set("sleep_room", 1);
         set("exits",([
             "west" : __DIR__"xiaoting",
]));
         set("coor/x",180);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
         replace_program(ROOM);
}
