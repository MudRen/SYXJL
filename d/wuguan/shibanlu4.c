// Room: /d/wuguan/shibanlu4.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
������һ��ʯ��·�ϣ������ȥ���Ǻ�Ժ�ˡ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"shibanlu3",
                "north" : __DIR__"houyuan",
        ]));
        setup();
        replace_program(ROOM);
}
