// Room: /d/wuguan/houyuan.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ������Щ�ɻ����µĵط��������ȥ���ǲ񷿣�������
һ��ˮ��������ææµµ�Ľ����������Լ��Ļ
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"shibanlu4",
                "north" : __DIR__"houyuan1",
                "east" : __DIR__"caifang", 
                "west" : __DIR__"shuifang",                                               
        ]));
        setup();
        replace_program(ROOM);
}
