inherit ROOM;

void create()
{
	set("short", "东廊");
	set("long", @LONG
这里是千佛庵东边的过道，过道上很安静。不时能听到从走廊两边传
来的木鱼声和颂经声。东边是文闲师太的禅房，西边是李明霞的禅房。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"chfang11",
  "south" : __DIR__"dlang5",
  "north" : __DIR__"dlang3",
  "east" : __DIR__"xfang3",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
