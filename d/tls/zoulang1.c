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
               "northwest" : __DIR__"zoulang2",
               "south" : __DIR__"shengdian",
       ]));
       set("coor/x",-80);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-80);
	set("coor/y",-100);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}
