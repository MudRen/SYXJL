
// Room: /jingzhou/yamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���𱾵ط������������ſ���Ҫ����ö��ˣ������ǲ���ˮ�������
���ӵ��������ߡ�������һ���ģ�gu�������������ĺ�ԩ�õģ�������
�߾������Ŵ����ˡ�
��
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"jingzhonglu2",
                "north" : __DIR__"yamendatang",
        ]));
/*
        set("objects", ([
                __DIR__"npc/xunbu" : 1,
        ]));
*/
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
