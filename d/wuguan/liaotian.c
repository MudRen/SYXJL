// Room: /d/wuguan/liaotian.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "������ѵ");
        set("long", @LONG
��һ������רΪ���ֶ���ģ�����������Կ���һλ����Ѱ����
�ΣУã�������ң����������򵥵Ľ�̸���ɡ��������Ϥ����֮
�󣬿��������ߣ�������Խ���һЩ���ð�յ�ָ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"maoxian",
        ]));
        set("objects", ([
                __DIR__"npc/tiatian" : 1,
        ]));
        
        setup();
        replace_program(ROOM);
}
