
// Room: /chang'an/yamendamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������Ŵ��ţ�������ľ���ųʰ��ֳ��������ྲ�����رܡ������ӷ�
����ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�������
������ǰѲ��
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"dongdajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}