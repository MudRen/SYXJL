
// Room: /jingzhou/nvrenjie3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ů�˽�");
        set("long", @LONG
������Ů�˽���Ϊ���ֵ�·���ˣ���������Ϊ������鱦������ã�
�������������һ����ʳ����Ϊ����ɿڵ�Сʳ������ǳ���¡��������
�е������ֵ��˶�Ҫ������ȥ����С�ԣ��ȵ����ϡ�
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nvrenjie2",
                "south" : __DIR__"xiaochidian",
                "west"  : __DIR__"huadian",
                "north" : __DIR__"nvrenjiepu5",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}