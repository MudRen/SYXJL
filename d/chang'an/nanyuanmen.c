
// Room: /chang'an/nanyuanmen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��Ժ��");
        set("long", @LONG
����һ��������������û������ʯ�棬�������浹�����������
������¥�������ǳ��ڵ�һ��ѧ�ã���ʱ������ѧ���ﴫ��ѧ�������ʵ�
��������������һ��С���˵ķ��ꡣ
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"jiekou3",
                "south" : __DIR__"laosunjia",
                "west"  : __DIR__"gulou",
                "north" : __DIR__"xuetang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}