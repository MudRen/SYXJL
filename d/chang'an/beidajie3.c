
// Room: /chang'an/beidajie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣������һ����¥����
������һ���ܸߴ�Ľ������������������¥�����������ַǷ���������
һ�ҵ��̣��򶫿��Ե�Ǯׯ��
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"qianzhuang",
                "south" : __DIR__"zhonglou",
                "west"  : __DIR__"dangpu",
                "north" : __DIR__"beidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}