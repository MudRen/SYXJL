// Room: /d/wuguan/shibanlu2.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
������һ��ʯ��·�ϣ���������涼��ϰ���ã���������������������ģ�
��������ݴ�����
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"xiwutang",
                "north" : __DIR__"xiwutang1",                
                "east" : __DIR__"wuguandating",                
                "west" : __DIR__"shibanlu3",                                
        ]));
        setup();
        replace_program(ROOM);
}
