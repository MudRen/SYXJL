// zoulang.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ֳ��ֺڵ����ȣ��������ǲؾ���
LONG
        );

       set("exits", ([
               "northwest" : __DIR__"zoulang3",
               "southeast" : __DIR__"zoulang1",
       ]));
       set("coor/x",-90);
	set("coor/y",-90);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-90);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-90);
	set("coor/z",30);
	set("coor/x",-90);
	set("coor/y",-90);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}
