
// Room: /chang'an/yanhuaxiang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�̻���");
        set("long", @LONG
����һ����ʯ�̾͵����ӡ�������һ���ܴ�Ĺսǽֿڡ�������Կ�
��һ��ܴ�Ĳ�¥����ʱ��Щ��̬ӹ�׵�Ů��վ����������㹴����ָͷ��
����ü��ʲô�ġ�������һ�Ҷĳ�������ԭ���ǳ����ΰ���ĵط�����
��һ��ʱ������Σ����ڿ�����Ҫǿ����ࡣ
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"dufang",
                "south" : __DIR__"jiekou4",
                "west"  : __DIR__"yihongge",
                "north" : __DIR__"xidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}