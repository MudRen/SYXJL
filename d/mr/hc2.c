#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long",@long
���Ų�����, ֻ�������г�ɽ�軨����ޱ�������, �������ǣţ��,
���º�, Ǿޱ֮��Ҳ��һ�䶼�ޡ��߳���ʮ�ɺ�, ֻ��ɽ��Ʒ�ֽ���, ż
��Ҳ��һ�������㲻��, ȴҲ���ֲ����䷨��
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"hc3",
             "east" : __DIR__"anbian",
]));
         set("coor/x",60);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}
