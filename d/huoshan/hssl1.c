
// Room: /huoshan/hssl1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������¥");
        set("long", @LONG
��������������ͻȻ����������ƾ�������ˣ�ԭ������������
ֻ�Ǵ�˵�еĺ�����¥����ʱ��������̫������ǿ�ҵغ濾�����
���壬������Լ��Ѿ����ֲ�ס�ˣ��Ų���·��ֻϣ������뿪
�����ط���
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"hssl2",
                "south" : __DIR__"hssl2",
                "west"  : __DIR__"hssl2",
                "north" : __DIR__"hssl2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}