
// Room: /jingzhou/xidajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����ʯ�����Ŀ����������·���߳������صĴ�����������ס
�����е����⡣��������һ�������ĵ��ۡ����۹�������������۫��·��
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"xidajie3",
                "south" : __DIR__"yingdulu",
                "west"  : __DIR__"xidajie",
                "north" : __DIR__"xuandigong",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}