inherit ROOM;
void create()
{
        set("short", "¹��������޹�˾���ݳ��ܴ���");
        set("long", @LONG
������¹��������޹�˾���ݳ��ܴ�����̨�ж��ڷ��Ÿ�ʽ���������
���㾡����ѡ��ǽ�Ϲ���һ������(paizi)��д�����µ�ͨ�档
LONG
        );

        set("no_fight", 1);
        set("no_study", 1);
        set("no_sleep_room",1);
        set("no_yun",1);

        set("item_desc", ([
                "paizi" : "����߹������Ҫ����������������һ��ͯ�����ۡ�\n",
        ]));

        set("objects", ([
                __DIR__"npc/songlaoban" : 1,
        ]));

        set("exits", ([
                "westdown"  : __DIR__"kedian",

        ])); 
        setup();
}


