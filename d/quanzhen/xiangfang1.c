// xiangfang1.c �᷿

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
��վ��һ�䲻����᷿�У������ɨ�ĺܸɾ�������ǽ��һ����ܣ����Ű�
ʮ��������������䣬������Ŀ�����ǰ����һ���鰸���ķ��ı��ٶ��߱�����
���Ҳ࣬��һ�Ű��������Ϸ���һ������β�ݱ�ɵ����š�
LONG
	);
        
	set("exits", ([
		"east" : __DIR__"neiyuan",
	   ]));
	set("coor/x",-110);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-110);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-110);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-110);
	set("coor/y",280);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}



