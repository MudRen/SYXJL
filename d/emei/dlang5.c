inherit ROOM;

void create()
{
	set("short", "东廊");
	set("long", @LONG
这里是千佛庵东边的过道，过道上很安静。不时能听到从走廊两边传
来的木鱼声和颂经声。东边是文怡师太的禅房，西边是苏梦清的禅房。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"chfang12",
  "north" : __DIR__"dlang4",
  "east" : __DIR__"xfang4",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
