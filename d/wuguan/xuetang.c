// Room: /d/wuguan/xuetang.c
// Date: 99/05/30 by Byt
inherit ROOM;
void create()
{
        set("short", "ѧ��");
        set("long", @LONG
����������ڵ�һ��Сѧ�ã������������ʶ�������һ��������
��������Ľ��ţ�������������Ӻ����ӣ��������Ǳ�ǽ��д�˼���
���֡���׳��Ŭ�����ϴ�ͽ�˱�����
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"shibanlu",
        ]));
        set("objects", ([
                __DIR__"npc/fang" : 1,
        ]));        
        setup();
}

