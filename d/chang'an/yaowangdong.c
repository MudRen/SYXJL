
// Room: /chang'an/yaowangdong.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "ҩ����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣������һ���ܴ�Ľ�
�ڹսǣ������ǹ�¥��������һ�ҵ��̣����ǳ�����˿������࣬������
�����������Ź��ʸ���ģ�����ˣ�ԭ����һ�ҹ���ꡣ�����������Ʈ��
һ���в�ҩζ��
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"beidajie2",
                "south" : __DIR__"yaopu",
                "west"  : __DIR__"jiekou1",
                "north" : __DIR__"guwandian",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}