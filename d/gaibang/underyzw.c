//add by angle
//underyzw.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ƶ���");
        set("long", @LONG
����һ���������õ�С�ض����Ϸ������м�˿��âͶ��������������
ʲô�ط��أ�������ȥ�����ɣ�
LONG );
        set("exits", ([
                "southwest" : __DIR__"yzwandao2",
                "out" : "/d/mr/yanziwu",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
