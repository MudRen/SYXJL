// Room: /d/wuguan/wupingfang.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��Ʒ��");
        set("long", @LONG
������Ʒ����һ������ӡ�����ŵ��������룬��������Ĺܼ���
�����渺��ģ�һЩ�����ڸ�����Ʒ���ߵĹܼ�˵��ʲô��
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"changlang2",
                "north" : __DIR__"changlang3",             
                "west" : __DIR__"shibanlu",                
        ]));
        set("objects", ([
                __DIR__"npc/laoli" : 1,
        ]));        
        setup();
        replace_program(ROOM);
}

