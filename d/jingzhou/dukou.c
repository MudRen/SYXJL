
// Room: /jingzhou/dukou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ɿ�");
        set("long", @LONG
��ǰ�ǲ��η����ĳ������������ϣ����ư��磬ȷʵ���˸�̾���ѡ���
���ɴ���������������һ�����������̯�����ϰ����˻�������Ľ��㡣��
ȥ��Զ���ǵ������������ٱ��������ٹ����Ͷ�������ȴ��ɴ��ڶɡ�
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"wanshoubaota",
         ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}