// Room: /d/gaibang/dlandao4.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
        set("short", "����");
        set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ�
������������Զ����һ�������������һ�����ڣ�����Զ������
ԼԼ����һЩ�о�������...� 
LONG
        );

        set("exits", ([
                        "southdown" : __DIR__"dlandao3",
                        "out" : "/d/dali/dahejieeast",
        ]));

        setup();
        replace_program(ROOM);
}
