// Room: /chang'an/jiekou1.c
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
                "east"  : __DIR__"yaowangdong",
                "south" : __DIR__"shajinqiao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}