// Room: /chang'an/shangdelu1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�е�·");
        set("long", @LONG
����һ����ʯ�̾͵Ĵ�֡�������һ�¸������ߵĴ��ӣ����ǿ���
һЩ�ٲ����������ԭ���������Ѳ�����ˡ������Ǿ����̳�����������
���ˡ�
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