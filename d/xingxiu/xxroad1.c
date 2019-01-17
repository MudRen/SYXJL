// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
你走在一条青石大道上。东面通向扬州城。
LONG
        );
        set("exits", ([
  "east" : "/d/city/ximen",
  "west" : __DIR__"xxroad2",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

