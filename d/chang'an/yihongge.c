
// Room: /chang'an/yihongge.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
��һ�߽�����һ����ұ��Ů������Χ�˹����������ĥ�䡣���ڵ���
�ŵƽ�ʣ������˱ǡ�������������������Ů�˷�վ���Զ��㷢����Ц��
һ���ĸ���������¡�ǰǰ����к��ſ��ˡ���¥�ϴ�����һ���������
�ε�������
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"yanhuaxiang",
                "up"    : __DIR__"yihonggeerlou"
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}