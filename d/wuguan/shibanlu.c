// Room: /d/wuguan/shibanlu.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
������һ��ʯ��·�ϣ���������������Ʒ�����㿴���в�����
�������Ÿ����Ĺ��ߣ����Ǳ߹�������������ݴ�����
LONG );
        set("outdoors", "wuguan");
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"zhangfang",
                "east" : __DIR__"wupingfang",                
                "west" : __DIR__"wuguandating",                
                "north" : __DIR__"xuetang",                
        ]));
        setup();
        replace_program(ROOM);
}
