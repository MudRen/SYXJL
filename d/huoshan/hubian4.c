
// Room: /huoshan/hubian4.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����ĺ�ˮ��hushui��������������չ�������ߣ���������
�Ĳݵأ�������һ˿��;�����ƣ��������ĺ�ˮ����������գ�
������Ȼ�ĺ������֣���һ���������ﶼ�����������ܡ�
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "south" : __DIR__"hubian3",
                "west"  : __DIR__"shanpo",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}