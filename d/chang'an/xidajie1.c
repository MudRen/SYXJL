
// Room: /chang'an/xidajie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�������������ţ�����
��һ����ʮ�ֽֿڣ�ֻ���������������ﲻ����������һ�Ӵ����̡�����
��ʱ�����������������������û�����������һ��ľ������
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"xidajie2",
                "south" : __DIR__"mugongfang",
                "west"  : __DIR__"westgate1",
                "north" : __DIR__"tiejiangpu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}