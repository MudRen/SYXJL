// Room: /chang'an/jiaochang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "У��");
        set("long", @LONG
���߽�У�������ջ�Ծ���ˣ���ʱ����һ��������֮������������һ
��̴���������ڳ��������ʯ�����࿼����һ���佫��һ�����ף�����
�˵���������档
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"shajinqiao2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}