// Room: /d/wuguan/zhandou.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "���ս��");
        set("long", @LONG
�����в���û��ս�������Ӳ�����û�д��ɱɱ��Ҫ����������
�㣬�ͱ���ѧ��������棬ֻ��ս��������ʹ�������������ǿʳ��
��������Ľ����ϻ���ȥ�����ԣ�һ��Ҫ֪�����ս�����͵���֪��
�������һ����������ս��������γ�Ϊ�����أ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "north" : __DIR__"wuguandayuan",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoqian" : 1,
        ]));
                
        setup();
        replace_program(ROOM);
}
