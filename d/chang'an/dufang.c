
// Room: /chang'an/dufang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�𹳶ķ�");
        set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ��������߽�
ȥ�Ƕġ���С���ķ��䣬�����Ƕġ��ƾš��ķ���(������)��ǽ�����۴�
����һ������(paizi)��
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"yanhuaxiang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}