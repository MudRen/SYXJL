
// Room: /chang'an/deshanglu3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
����һ����ʯ�̾͵Ĵ�֣����ϱ���ͷ���졣������һ���������ܴ�
��ʮ��·�ڡ�������һ���սǽֿڡ�������һ��˿�����ӣ����������
ͦ���������һ���ӻ��̡�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"sichouhang",
                "south" : __DIR__"jiekou3",
                "west"  : __DIR__"zahuopu",
                "north" : __DIR__"dongdajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}