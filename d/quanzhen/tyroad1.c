// tyroad1.c ʯ��

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ������ʵ��ʯ��·����ʱ���н���ͺ����˴��������߹���̧ͷ��
������ΰ��������������������֮�У�Ρ��׳�ۡ��ϱ�һ��ʯ��ͨ��ɽ�£�
��Լ�ɼ�Զ���һ�ƬƬ��������Ŀ��
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : __DIR__"shanmen",
                "northup" : __DIR__"tyroad2",
        ]));
        set("coor/x",-90);
	set("coor/y",210);
	set("coor/z",170);
	set("coor/x",-90);
	set("coor/y",210);
	set("coor/z",170);
	set("coor/x",-90);
	set("coor/y",210);
	set("coor/z",170);
	set("coor/x",-90);
	set("coor/y",210);
	set("coor/z",170);
	setup();
        replace_program(ROOM);
}
