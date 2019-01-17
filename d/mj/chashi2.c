// Room: chashi2.c

inherit ROOM;

void create()
{
        set("short", "茶室");
        set("long", @LONG
一进到这里就可以闻到一股茶叶的清香，墙角有个炖水的小炉，
上面的水壶已经开始往外“嘶嘶”地冒水气了。橱架上的托盘里整齐
地放着几个很漂亮的雕花茶盅。西面是厅房。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tingtang",
]));
        set("no_clean_up", 0);

        set("coor/x",-110);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",110);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

