
// Room: /huoshan/guanmulin6.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��ľ��");
        set("long", @LONG
ת�˰��죬��ǰȴ������һ��ɽ�ڣ����������������·�ľ�
ͷ�ˣ���ʵ��ɽ�ڵ�ס��·��ȥ�򡣿���ɽ�ǵ�һƬ�ط���һ��Ƭ
��ľ(guanmu)���ø���ïʢ���·�����Ϊ�ض�������һ�㡣
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "south" : __DIR__"guanmulin5",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}