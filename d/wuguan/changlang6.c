// Room: /d/wuguan/changlang6.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�һֱͨ���Ժ���ϱ��������䳡��
LONG );
        set("outdoors", "wuguan");
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"xiwuchang1",
                "north" : __DIR__"shibanlu3",                
        ]));
        setup();
        replace_program(ROOM);
}
