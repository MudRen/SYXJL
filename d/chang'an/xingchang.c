// Room: /chang'an/xingchang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�̳�");
        set("long", @LONG
�����ǳ����������̵ĵط���ǰһ��ʱ��ٸ��´������γ����ڵ���
�����ոմ�����һ�����ﷸ����̨���滹��Щ�����Ѫ�ա�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"deshanglu1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}