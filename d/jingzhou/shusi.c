
// Room: /jingzhou/shusi.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����������������������һ����Ⱦ�����ϵ���� (shelf)���������յ�
���������ǵ���ѡ����¼�����յ۹��ķ���������������ġ�ңԶĥ��
ȥ�Ĵ�˵��������Ķ�(read)����Щ���ϵĹ��¡�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"xidajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}