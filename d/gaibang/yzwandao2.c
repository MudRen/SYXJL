//add by angle
//yzwandao2.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG );
        set("exits", ([
                "southwest" : __DIR__"underyzw",
                "northeast" : __DIR__"yzwandao1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
