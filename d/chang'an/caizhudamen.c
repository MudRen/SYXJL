
// Room: /chang'an/caizhudamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴�
�����࣬���������������������Ϲ�������������д�š��ߡ��֡���
���ǵ����׸����������������ơ������ǹ�������������˹�����
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"caizhudayuan",
                "east"  : __DIR__"shajinqiao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}