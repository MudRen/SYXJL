// sheshentai.c ����̨

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
��ǰ�Ǹ������Բƺ������Ⱥɽ����������������أ�ˮ��ӳ�£�����
���������������ż�������������ӳ��ˮ�С�����ɽ���м�ʮ�����ᣬ�м�
�������ر��ΰ���Ǿ���ȫ��̵����ڵء�
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"eastdown" : __DIR__"chexiangtan",
		"westdown" : __DIR__"yuqingchi",
        ]));
	set("coor/x",-80);
	set("coor/y",170);
	set("coor/z",140);
	set("coor/x",-80);
	set("coor/y",170);
	set("coor/z",140);
	set("coor/x",-80);
	set("coor/y",170);
	set("coor/z",140);
	set("coor/x",-80);
	set("coor/y",170);
	set("coor/z",140);
	setup();
	replace_program(ROOM);
}



