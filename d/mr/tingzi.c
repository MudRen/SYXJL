#include <room.h>
inherit ROOM;
void create()
{
         set("short","ͤ��");
         set ("long",@long
���Ǹ���С��ͤ�ӣ������ܹ���������ȫ���ľ�ɫ��Զ����һƬӣ��԰��
���м���С���ڱ��̵ĺ������������󣬺�����һ��ľ��ͨ����е�ͤ�ӡ�
��ˮ�صļ�ɽ����һ���ں����Ķ�Ѩ�� 
long);
         set("exits",([
             "westdown" : __DIR__"c14-1",
]));
         set("objects",([
             __DIR__"npc/wyy" : 1,
]));
         set("coor/x",150);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
         replace_program(ROOM);
}
