
// Room: /jingzhou/jingzhonglu2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����棬�ƺ����Ըо�����������
�����Ի͵Ĺ�ȥ�����������ţ���������ԭ·�����治ʱ�������Ӳ�����
������
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"zhangjuzhengjie",
                "south" : __DIR__"quyuanlu",
                "west"  : __DIR__"jingzhonglu",
                "north" : __DIR__"yamen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}