
// Room: /jingzhou/jianyuguodao1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
һ�����͸�����ɭ�ĸо����������η�ɢ����һ��ù����ζ�������ھ�
�����󺷣�Υ�����˿��������٣��������������������ģ������������
��Ѻ�أ��ұ��Ǹո�ץ������û�ж���ķ��ˡ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nanlao",
                "south" : __DIR__"jianyuguodao2",
                "west"  : __DIR__"nvlao",
                "north" : __DIR__"jianyudamen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}