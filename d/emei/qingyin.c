#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
"���������ԡ�"GRN"˫������"NOR"�����ƣ�������ţ������������룬ɽ�͵��䣬\n"
"������˫���ţ��ֱ�ɿ�������Ͱ���������Ϣͤ�У���Զɽ���ԣ�����\n"
"ˮ������ȷ��һ�֡�����Ū��Ӱ���������˼���⾳����\n"
        );

        set("exits", ([
                "southdown" : __DIR__"shenshui",
		"eastup" : __DIR__"wannian",
                "westup" : __DIR__"gate",
               ]));
        set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",90);
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",90);
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",90);
	setup();
        replace_program(ROOM);
}