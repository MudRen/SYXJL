inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
        ����һ��ҩ�̣�СС�ķ����ﵽ���������ŵ�ҩ��ζ�������ڹ�̨��
�ߵ�һ���������ڸ�һ�����˰�������һ����ר�ĵ����ӡ�һ��С���վ
�ڹ�̨��������ƽæ��Ҫ������̨������һ�ż�Ŀ��(jiamubiao)��
LONG
        );
//        set("outdoors", "jingzhou");
        set("item_desc", ([
                "jiamubiao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
������: \t��ʮ������
������ҩ���ϰ����顣\n",
        ]));


        set("objects", ([
                "/d/jingzhou/npc/huoji" : 1,
        ]));

        set("exits", ([
                "east"  : __DIR__"nanmendajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

