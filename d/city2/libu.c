//libu.c �񲿴���

inherit ROOM;

void create()
{
        set("short", "�񲿴���");
        set("long", @LONG
��������񲿴��ã�������ǰ����һλ�ɷ���ǵ����ˣ�������
�����飬���¹���ǡ��Ĵ��ĺ�--С�����С��������԰�����
�����ڣ��������ܵõ�������ʶ�����������ˡ���ǰ��Ŀ�Ĵ�����
���ྲ����
LONG
        );

        set("exits", ([ 
                      "north" : __DIR__"yamen",
                     ]));
        set("objects", ([
                __DIR__"npc/shutong": 2,
                __DIR__"npc/xiaoyu": 1,
        ]) );

        setup();
}

