// caoping.c
inherit ROOM;
void create()
{
        set("short","��ƺ");
        set("long",
             "������һ�鷼��ƺ���̲����𣬺������裬���˸е���⡣\n"
         "����ż��Ҳ�������˻��ߣ�\n"
        );
        set("exits", ([
                "west" : __DIR__"shijie",
        ]));
         set("objects" , ([
             __DIR__"npc/caihuashe" : random(2),
             ]));
        set("outdoors", "baituo");
        set("coor/x",-120);
	set("coor/y",-50);
	set("coor/z",-20);
	set("coor/x",-120);
	set("coor/y",-50);
	set("coor/z",-20);
	set("coor/x",-120);
	set("coor/y",-50);
	set("coor/z",-20);
	set("coor/x",-120);
	set("coor/y",-50);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}
