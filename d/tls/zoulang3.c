// zoulang3.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是一段又长又黑的走廊，向西北是藏经阁。
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
