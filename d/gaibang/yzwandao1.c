// add by angle 
// yzwandao1.c
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG );
        set("exits", ([
                "southwest" : __DIR__"yzwandao2",
                "northeast" : __DIR__"undertre",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

