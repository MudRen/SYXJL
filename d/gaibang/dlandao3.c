// Room: /d/gaibang/dlandao3.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
        set("short", "����");
        set("long", @LONG
����ؤ�� �������ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG
        );

        set("exits", ([
                        "southwest" : __DIR__"dlandao2",
                        "northup" : __DIR__"dlandao4",
        ]));

        setup();
        replace_program(ROOM);
}
