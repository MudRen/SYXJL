#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long",@long
���Ų�����, ֻ�������г�ɽ�軨����ޱ�������, �������ǣţ��,
���º�, Ǿޱ֮��Ҳ��һ�䶼�ޡ��߳���ʮ�ɺ�, ֻ��ɽ��Ʒ�ֽ���, ż
��Ҳ��һ�������㲻��, ȴҲ���ֲ����䷨���������ׯ���ˡ�
long);
         set("outdoors","mr");
         set("exits",([
             "north" : __DIR__"anbian",
             "east" : __DIR__"zhuangmen",
             "west" : __DIR__"hc3",
]));
         set("coor/x",70);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
         replace_program(ROOM);
}
