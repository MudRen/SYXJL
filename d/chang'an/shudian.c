
// Room: /chang'an/shudian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
����һ�Һ�С�����ݣ���������Ҳ������һЩ�������õ��鼮����
���ǽ�Ϲ���һ�����Ϸ��ӵĻ������������һ���������β���ض���
����ѧ������������������Ҳֻ��Ϊ�˺��ڶ��ѡ�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"nandajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}