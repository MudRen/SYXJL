// zoulang3.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ֳ��ֺڵ����ȣ��������ǲؾ���
LONG
        );

       set("exits", ([
               "enter" : __DIR__"cjlou",
               "southeast" : __DIR__"zoulang2",
       ]));
       set("coor/x",-100);
	set("coor/y",-80);
	set("coor/z",30);
	set("coor/x",-100);
	set("coor/y",-80);
	set("coor/z",30);
	set("coor/x",-100);
	set("coor/y",-80);
	set("coor/z",30);
	set("coor/x",-100);
	set("coor/y",-80);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}
