
// Room: /jingzhou/tading.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��С������ȥ�����������ư���ĳ����������и���Ĵ�ֻ����������
������һƬ���������֣�ȷʵ�Ǹ��õط���
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "down"  : __DIR__"wanshoubaota",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}