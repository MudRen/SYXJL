inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "��������");
        set("long", 
"�����ǳ����ǵı����ţ�ֻ�������Ϸ����������֡�"HIB"

                   ��    ��    ��
\n"NOR
"    �����������������ģ�˿��֮·����㣬���ڳ�͢��ֹ͵����˽����
֮�����Ʒ���أ������������Ѿ���ʼ�̲��ʮ���ϸ��ˡ������Ǻܴ��
�ݵء�\n"
 );
        set("outdoors", "chang'an");

        set("exits", ([
                "south"  : __DIR__"northgate1",
                "north"  : __DIR__"caodi3",
                "east"   : __DIR__"caodi1",
                "west"   : __DIR__"caodi2",
        ]));
/*
        set("objects", ([
                __DIR__"npc/pi"   : 1,
                __DIR__"npc/bing" : 2,
        ]));
*/
        setup();
        replace_program(ROOM);
}

