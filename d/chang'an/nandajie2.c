
// Room: /chang'an/nandajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣�ϱ߾�����ȸ�ţ���
��������㳡��������һ�����С�������һ�������¥�󣬹��š�������
�ꡱ��������
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"yuelaikedian",
                "south" : __DIR__"gulou",
                "west"  : __DIR__"mahang",
                "north" : __DIR__"zhonglou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}