// Room: /d/wuguan/changlang4.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�ͨ����������ң����ﾲ���ĵģ�û��ʲô������
����������������ɽ�����������գ�����������������ֻ����һ��
������
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"wuguandating",
                "north" : __DIR__"woshi",                
                "east" : __DIR__"shufang",                
        ]));
        setup();
        replace_program(ROOM);
}
