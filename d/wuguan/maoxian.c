// Room: /d/wuguan/maoxian.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "ð�ջ���");
        set("long", @LONG
���������ѧ��һЩð�յĻ���ָ����磺��������������
�յȵȡ��Լ���ѧ��һЩ�ճ������ָ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"baishi",
        ]));
        set("objects", ([
                __DIR__"npc/orange" : 1,
        ]));
            
        setup();
        replace_program(ROOM);
}
