// Room: /d/wuguan/zhangfang.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
����������ڵ�һ���ʷ�������һ���ʷ���������������������ʡ�
�����µ�����Χ���ʷ���������������ѻ���������Ǯ��������ǽ
�Ϲ���һ������(paizi)��
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "north" : __DIR__"shibanlu",
        ]));
        set("objects", ([
                __DIR__"npc/zhangfang" : 1,
        ]));                
        setup();
        replace_program(ROOM);
}
