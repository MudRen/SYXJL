
// Room: /jingzhou/jingnanlu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
������һ������ʯ������·���ϣ����µĴ���ʯ����������Ѿ��ܾ�
Զ�ˣ����߿��Կ��������سǵľ�ʿ�����洫���������������Ľ�����ײ
��������������һ���������ǳ��ι̵ļ�����
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"dongmen",
                "south" : __DIR__"jianyudamen",
                "west"  : __DIR__"jingnanlu",
                "north" : __DIR__"datiepu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}