// Room: /d/mingjiao/mjdimen.c
// Date: XXL 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "�ݵ�");
    set("long", @LONG
����һƬ���ݵأ���Ӣ�ͷף������裬��¶Ϧ�⣬����
��Ƣ������С����ݺ����Ӱ����Ƥ���ˣ����������������
��÷�����������������ǽ������ܣ��ߵ��������Ҳƽ��
�����ᣬ��ȴ����ɱ�⡣
LONG
    );

    set("exits", ([
        "northeast" : __DIR__"mjdimen1",
        "southwest" : __DIR__"mjsimen1",
    ]));

    set("outdoors", "mingjiao");
    set("coor/x",-100);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

