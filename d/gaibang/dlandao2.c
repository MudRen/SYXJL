// Room: /d/gaibang/dlandao2.c
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
                        "east" : __DIR__"dlandao1",
                        "northeast" : __DIR__"dlandao3",
        ]));

        setup();
        replace_program(ROOM);
}
