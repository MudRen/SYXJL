// Room: /chang'an/jianyuguodao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
һ���ںڵ����ȣ�ֻ��һյ�͵Ʒ���һ��΢���Ĺ⣬������һ������
��ù��ζ��
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"silao",
                "south" : __DIR__"nanlao",
                "west"  : __DIR__"jianyudamen",
                "north" : __DIR__"nvlao",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}