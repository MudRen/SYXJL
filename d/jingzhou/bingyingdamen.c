
// Room: /jingzhou/bingyingdamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��Ӫ����");
        set("long", @LONG
����վ�ڱ�Ӫ���ſڣ������ɹű�Ҫ�ٴι���������ҥ�����𣬾���
���ؽ�Ҳ�ڻ�����ս�������һ�ż�ª��Ӫ�������Կ��������Ʒ��ľ�ʿ
���ڲ�������ʱ�ش����ź���������øϿ��߿�����ñ�����̽��ץ����
��ԩ���ˡ�
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"zhangjuzhengjie",
                "north" : __DIR__"bingying",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}