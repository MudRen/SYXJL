// Room: /d/mingjiao/shanjiao.c
// Date: XXL 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����ɽ��");
    set("long", @LONG
������ǧ�����صĶ�´��Զ������ƺƣ��������ơ�������
Ұǧ����������������ɽΡΡ���������߳�����ְ˰���
�����̾���������Ⱥɽ֮�С�����----�Ƕ������ֺ�����������
�ط����������������������ĺ��ֵܣ�����������а������
��������Ⱥɽ֮�󣬵ȴ�����ȥ��д��һ�����ִ��档
LONG
    );

    set("exits", ([
        "west" : __DIR__"tomen2",
        "east" : __DIR__"gebitan5",
    ]));

    set("outdoors", "mingjiao");
    set("coor/x",-100);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

