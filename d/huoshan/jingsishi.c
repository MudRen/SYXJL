
// Room: /huoshan/jingsishi.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��˼��");
        set("long", @LONG
һ��յ����ķ��ӣ������ǽ��(qiang)������ģ����Ϸ��ż�
�����Ƶĵ��ӣ������Ļ�������������������ھ�˼��
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "south" : __DIR__"zoulang5",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}