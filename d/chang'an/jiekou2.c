// Room: /chang'an/jiekou2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ֿ�");
        set("long", @LONG
����ǹսǽֿڣ��кܶ�С��С������������ߺ���ţ��������ǵ���
Ʒ���������������ʯ�̾͵Ĵ�֡�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"chongwujie",
                "south" : __DIR__"shangdelu1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}