
// Room: /jingzhou/nanmendajie��.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "���Ŵ��");
        set("long", @LONG
�������ַǷ�������Ĺ���������Ů�˽ּ�������ɽ�˺��ˣ����
�ϵ��˴�����Ϣ����������������һƬ��õķ�������
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"guanmiao",
                "south" : __DIR__"nanmen",
                "west"  : __DIR__"nvrenjie1",
                "north" : __DIR__"nanmendajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}