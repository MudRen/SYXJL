
// Room: /chang'an/deshanglu1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
����һ����ʯ�̾͵Ĵ�֡�������һ�¸������ߵĴ��ӣ����ǿ���
һЩ�ٲ����������ԭ���������Ѳ�����ˡ�������һ����ͬ����������
�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"xunbufang",
                "south" : __DIR__"shangdelu2",
                "west"  : __DIR__"xingchang",
                "north" : __DIR__"jiekou2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}