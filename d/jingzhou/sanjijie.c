
// Room: /jingzhou/sanyijie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�����ֵ������Ǹ�������ʱ����������԰������ĵ�ʶ������ģ���
�ߵĽ�����������ľ�Ƹ�¥�����������ɵúܡ�������һ�Ҿ�¥�����濴
�����ƺ���һ���ջ��
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jiulou",
                "south" : __DIR__"sanyijie",
                "west"  : __DIR__"kedian",
                "north" : __DIR__"beimen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}