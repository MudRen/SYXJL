
// Room: /chang'an/tiejiangpu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��ո��߽��ţ��;���һ�����������������������һ�������̣���
�����ųಲ�ĺ��������Ŵ������û����յû���������һ���Ϻ�����һ
�������ŷ��䡣
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"xidajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}