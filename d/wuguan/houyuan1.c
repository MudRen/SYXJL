// Room: /d/wuguan/houyuan1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ������Щ�ɻ����µĵط��������ȥ����ľ�񷿣�����
��һ����������ææµµ�Ľ����������Լ��Ļ
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"houyuan",
                "north" : __DIR__"houyuan2",
                "east" : __DIR__"mufang", 
                "west" : __DIR__"mafang",                                               
        ]));
        setup();
        replace_program(ROOM);
}
