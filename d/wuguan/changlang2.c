// Room: /d/wuguan/changlang2.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�����������ڵ���Ʒ����Ҫ����������µ��˶���ȥ
��Ʒ���칤�ߣ��ϱ��Ƕ����䳡��
LONG );
        set("outdoors", "wuguan");
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"dongwuchang1",
                "north" : __DIR__"wupingfang",                
        ]));
        setup();
        replace_program(ROOM);
}
