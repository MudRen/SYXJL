
// Room: /chang'an/dongdajie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�����ǳ������ţ�ԶԶ
�ؿ��Կ����سǵľ�ʿż������С�������һ�Һܴ�ľ�¥����ʱƮ��
һ����������ζ��������һ��ϷԺ��
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"eastgate1",
                "south" : __DIR__"xiyuandamen",
                "west"  : __DIR__"dongdajie2",
                "north" : __DIR__"diyilou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}