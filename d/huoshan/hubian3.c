
// Room: /huoshan/hubian3.c
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
                "southeast" : __DIR__"hubian1",
                "north" : __DIR__"hubian4",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}