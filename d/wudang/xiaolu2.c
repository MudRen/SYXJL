// xiaolu2.c �ּ�С��
// by Xiang

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
    ������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ������
LONG );
        set("exits", ([
                  "north" : __DIR__"xiaoyuan",
                "west" : __DIR__"xiaolu",
        ]));
        create_door("north", "����", "south", DOOR_CLOSED);
        set("objects", ([
                CLASS_D("wudang")+"/qingfeng": 1,
                CLASS_D("wudang")+"/mingyue": 1,
        ]));
        setup();
        replace_program(ROOM);
}

