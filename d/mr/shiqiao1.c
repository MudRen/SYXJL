#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","Сʯ��");
         set("long",@long
����һ��СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����ʯ�ŵĶ�����
һ������ʯ�̳ɵ�С������������٢��ɽׯ��ǰԺ��
long);
set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"xiaojing5",
             "west" : __DIR__"qianyuan",
]));
        set("coor/x",100);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
