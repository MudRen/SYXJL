// Room: /d/mingjiao/tomen2.c
// Date: XXL 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��ʯ��");
    set("long", @LONG
���ֽ�����������ǰ������һ������ʯ�������ֱͨ��ǰ
�����ص�ϡϡ��������ż��ð�����ȴ�Եøߴ�ͦ�Σ��������
֦������ո߸���չ�š��ɴ�����ԶԶ��ȥ����һ����ש���ߵ�
�ֺ��լ��
LONG
    );

    set("exits", ([
        "west" : __DIR__"tomen1",
        "east" : __DIR__"shanjiao",
	"south" : __DIR__"mjsimen",
    ]));

    set("outdoors", "mingjiao");
    set("coor/x",-110);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

