// yading.c

inherit ROOM;

void create()
{
    set("short", "�¶�");
    set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿��������
���˼Ҳ��࣬���Ҵ�����ܼ���������һ�����������ʯ·�������Ǽ�
��ʵ����լ��
LONG
        );
    set("exits", ([ 
                "east"  : __DIR__"eroad1",
                "west"  : __DIR__"eroad3",
                "north" : __DIR__"ehouse2",
]));
    set("outdoors", "��ɽ��");

//    setup();
    replace_program(ROOM);
}

