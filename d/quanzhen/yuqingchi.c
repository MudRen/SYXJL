// yuqingchi.c �����

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����������أ�����Ⱥɽ����������β��羵����ˮ������������
���͵��䡢�������֣�һ������浾����崿�����ķ�⡣���Ͼ���ȫ��
�̡�
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"northup" : __DIR__"shijie3",
		"eastup" : __DIR__"sheshentai",
       ]));
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",130);
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",130);
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",130);
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",130);
	setup();
	replace_program(ROOM);
}



