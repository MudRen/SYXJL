// Room: /chang'an/xunbufang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ѳ����");
        set("long", @LONG
�������Ѳ�����ˣ��ɿ����¿�ȡ�Ŀ���������ÿ���˶�Ҫ�ȵ�����
��������һ��ʱ�䣬��Ҫ��������Ѳ�ߣ�ץץ�ﷸС͵ʲô�����顣����
����Ϣ�ң�������һ���С����ʱ�η���
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"xiuxishi",
                "west"  : __DIR__"shangdelu1",
                "north" : __DIR__"laofang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}