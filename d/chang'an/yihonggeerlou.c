
// Room: /chang'an/yihonggeerlou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������¥");
        set("long", @LONG
��վ������Ժ��¥���������������첻�����ơ�������һ���С�ң�
���ڲ��õ�Ҳ�򵥣������ϲ��õþ��Ծ��£�ͻȻ�������Ī�����ջ��
�嶯������������ǧ�������ڵ��ֶ����㣬���뵽���ǿ��ܾ������ս���
�е��۸��ڶ��Ĵ���Ů����ʱ��Ϊ���ġ�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "down"  : __DIR__"yihongge",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}