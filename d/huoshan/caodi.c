
// Room: /huoshan/caodi.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
����һƬ�����͵Ĳݵأ���������о����Ǻ������
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"yongdao4",
                "south" : __DIR__"huajing1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}