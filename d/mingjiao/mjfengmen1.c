// Room: /d/mingjiao/mjfengmen1.c
// Date: XXL 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
���������е�һ��СԺ����Ӱ������������������ϱ�����
һ�����ᣬ�����������͵��ͷ�ҵ��ӵ�����������
LONG
    );

    set("exits", ([
        "northwest" : __DIR__"mjfengmen",
	"north" : __DIR__"foshe",
	"south" : __DIR__"daoshe",
    ]));

    set("outdoors", "mingjiao");
    set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

