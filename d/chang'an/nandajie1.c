
// Room: /chang'an/nandajie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
�����ǳ������ϴ�ֵ���ͷ�����������ȸ���š��в���ͷ������
�������ڶ�����룬�޷���ȥ���ͻ�����ġ�������鷨��ҵ��ֱʡ�����
��һ����ꡣ
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"beilin",
                "south" : __DIR__"southgate1",
                "west"  : __DIR__"shudian",
                "north" : __DIR__"gulou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
