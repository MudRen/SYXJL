
// Room: /huoshan/hubian1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����һ��ˮ�ǡ�����ƽ������һ�澵�ӣ����ܳ�����������
�еĺ���������Ϊ��ĵ����������˼�ֻ��������������񣬴�Į
�������һ��ƣ����ʱ������ɢ���㲻�ɵö��⳱ʪ�Ŀ������˼�
���������
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"hubian2",
                "northwest" : __DIR__"hubian3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}