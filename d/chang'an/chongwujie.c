
// Room: /chang'an/chongwujie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����ʯ�̾͵����ӡ�������ͷ���졣������һ���սǴ�֡�
�����ǳ�����ݣ���˵�����Ľ�ͷҶС������Ҳ�ǽ������ˣ���������
һ�����������˳ơ�����ЦЦè����
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"jiekou2",
                "west"  : __DIR__"beidajie2",
                "north" : __DIR__"changanwuguan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}