
// Room: /chang'an/shajinqiao2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣��������У������ƽ
����;����һ����㣬�����˿��Ե���һ����λ��΢����١�����˵����
������ǰ�ˣ�����Ҫ������书����ҪҪ������һ������ѧ������
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"jiaochang",
                "south" : __DIR__"xidajie2",
                "west"  : __DIR__"zhenxibiaoju",
                "north" : __DIR__"shajinqiao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}