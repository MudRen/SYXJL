
// Room: /chang'an/shajinqiao1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һ����ʯ�̾͵Ĵ�֡�������һ���սǽֿڡ�������ƽ������;
����㣭������������˵���������ٱ�ԭ��Ҫ���ˣ�����Ҫ�������ѧ֪
ʶ����Ҫ������һ�����������С�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"kaochang",
                "south" : __DIR__"shajinqiao2",
                "west"  : __DIR__"caizhudamen",
                "north" : __DIR__"jiekou1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}