
// Room: /chang'an/diyilouerlou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��һ¥��¥");
        set("long", @LONG
����¥�����������ζ�˱Ƕ����������̲�סҲ��������Ҫ��һ�ݾ�
�˲źá�����Ĺ˿ͺܶ࣬�����Ѿ�������ϯ�ˣ��������õ�ǰ��ߺ�ȣ�
��ֱæ�������ˡ�����Ҫ�Է���ÿ��Ҹ�������(zuo)��������������һ��
�˵�(caidan)��
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "down"  : __DIR__"diyilou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}