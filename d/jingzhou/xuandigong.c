
// Room: /jingzhou/xuandigong.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���۹�");
        set("long", @LONG
���۹�ʼ�����ƴ�����ģ����������ڱ����Ļʵ��ŷ���̣�������
��ĵ�ʿ�Եø��Ӱ�����������������Ĵ��ڣ�æµ���Լ������飬��ֻ��
��һƪ��̾�����ε��뿪��
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"xidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}