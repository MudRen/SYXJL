
// Room: /jingzhou/yamendatang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���Ŵ���");
        set("long", @LONG
һ����Ծ���������ľ��Ǵ����ϸ����ġ������������ĸ����֣�����
��һ����������������ű��ص�֪����������˼���ˣ�������һ������
��ģ������֪��Ϊʲô����˵���ڴ˵����μ����ˣ��Ա߷��Ÿ�����̾ߡ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"yamen",
                "north" : __DIR__"neizhai",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
