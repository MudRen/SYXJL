
// Room: /chang'an/beidajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����������ʯ�����ϣ������ǳ�������һ��ʮ��·�ڣ���
���������ﲻ����������ҩ�������򶫿ɴ����֡������Ѿ����Կ�����
�ߴ�������¥�ˡ�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"chongwujie",
                "south" : __DIR__"beidajie3",
                "west"  : __DIR__"yaowangdong",
                "north" : __DIR__"beidajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}