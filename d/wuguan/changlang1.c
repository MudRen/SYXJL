// Room: /d/wuguan/changlang1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�ͨ�����䳡�����������ģ��������֡�
LONG );
        set("outdoors", "wuguan");
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "west" : __DIR__"wuguandayuan",
                "east"  : __DIR__"dongwuchang",                                             
        ]));
        setup();
        replace_program(ROOM);
}
