// Room: /chang'an/beidajie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�������������ţ��ϱ�
�Եúܷ�æ��������һ��ݣ�һ�����顰�衱������ڷ��������ҡҷ�ţ�
һ�ɹɲ������������������һ�������С�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"chaguan",
                "south" : __DIR__"beidajie2",
                "west"  : __DIR__"luotuohang",
                "north" : __DIR__"northgate1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}