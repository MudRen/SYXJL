
// Room: /chang'an/xuetang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "ѧ��");
        set("long", @LONG
�����ǳ�����ѧ�ã�����������һ����Ⱦ��һλׯ���������ѧ����
������һ��̫ʦ���Ͻ�ѧ��������������������ѧ��ѧ����һ�Ź��ⰻȻ
���鰸������������ǰ�棬���ϰ��ż��������˵���װ�鼮�������·���
������ѧ��ѧ����
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"nanyuanmen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}