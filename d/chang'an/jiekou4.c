// Room: /chang'an/jiekou4.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ֿ�");
        set("long", @LONG
����ǹսǽֿڣ��кܶ�С��С������������ߺ���ţ��������ǵ���
Ʒ������ͱ�������ʯ�̾͵Ĵ�֡�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"changjie",
                "north" : __DIR__"yanhuaxiang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}