// Room: /d/wuguan/wuguandating.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��ݴ���");
        set("long", @LONG
��������ݴ��������п�������һ�Ű����������Ϲ��Źع�����λ��
�Ա߷���������ɻ�ƿ�����ż�֧��ȸ�ᣬǽ��д�Ŵ���һ�����䡱��
���������Щ���ڽ����ϴ������ֽ�ϴ�����ˣ������ݿ����������ݣ�
�������Ǹ����ȣ�һֱͨ����������ҡ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"wuguandayuan1",
                "north" : __DIR__"changlang4",                
                "east"  : __DIR__"shibanlu",                
                "west" : __DIR__"shibanlu2",
        ]));
        set("objects", ([
                __DIR__"npc/zhu" : 1,
        ]));        

        setup();
        replace_program(ROOM);
}
