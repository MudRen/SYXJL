// Room: /d/kunlun/shanjiao.c

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����ɽ��");
    set("long", @LONG
������ǧ�����صĶ�´��Զ������ƺƣ��������ơ�������Ұǧ�
���������������ɽΡΡ���������߳�����ֵ������ɾ���������Ⱥ
ɽ֮�С�����----�Ƕ������ֺ����������ĵط������������������
����ĺ��ֵܣ�����������а��������������Ⱥɽ֮�󣬵ȴ�����ȥ��
д��һ�����ִ��档
LONG
    );

    set("exits", ([
	"west" : "/d/kunlun/shanlu",
        "east" : "/d/xingxiu/shanjiao",
      
    ]));

    set("outdoors", "mingjiao");
    set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",30);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

