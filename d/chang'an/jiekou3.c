// Room: /chang'an/jiekou3.c
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
                "west"  : __DIR__"nanyuanmen",
                "north" : __DIR__"shangdelu3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}