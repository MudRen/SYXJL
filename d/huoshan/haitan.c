
// Room: /huoshan/haitan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��̲");
        set("long", @LONG
����ɫ��ɳ̲����ģ��������棬���������Լ�һ��������
��ӡ���ں�ů�������£�����ĺ��紵��ͷ��˳�������˸о�
�����������ĺ����Ĵ��Ű��ߵĽ�ʯ�������ȵ�������տ���Ĵ�
���������������Ŀ����������һ�ߡ����İ�����һȺȺ��ɫ��
�����ȶ��ų��ʱ������һ����߰��Ľ�����
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "south" : __DIR__"shandong7",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}