
// Room: /jingzhou/jiyuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
��һ�߽��������������ײ����͵�Ů�˷�վ���Զ��㷢����Ц����ʱ
�ػ�������ĸ�ɫ˿���������㡣���ڵƻ�ͨ���������˱ǡ��ĸС������
�������ŷ�Ĩ��������ɫ�����������¡�ǰǰ����к��ſ��ˣ�æ����ͣ��
��ʱ��¥�ϴ�������������ε�������
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"sanyijie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}