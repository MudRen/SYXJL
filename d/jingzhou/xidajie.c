
// Room: /jingzhou/xidajie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������������ϣ����ż�ʵ����ʯ����档�����������ţ���ϡ����
�����سǹٱ�����Ӱ�����ϱ����ʵĶ�����������һ�𡣱�����һ������
�ŵ�������
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"xidajie2",
                "south" : __DIR__"sishu",
                "west"  : __DIR__"ximen",
                "north" : __DIR__"shusi",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}