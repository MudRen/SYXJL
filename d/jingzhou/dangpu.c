
// Room: /jingzhou/dangpu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ�ҿ�����ʮ����ͨ�ĵ��̣�һ����߸ߵĹ�̨���������ǰ��
��̨�Ϸ���һ���̽����ӣ�paizi)�������������Ѿ����ڽ�������ˣ����
�ܳ�ʱ��û�в�ϴ������̨�������ϰ壬һ˫�����ĵ�����ش������㡣
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"nanmendajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}