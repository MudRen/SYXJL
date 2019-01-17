inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
走完长长的石阶，到了一个很热闹的广场。这里是报国寺大门前的广
场，北面就是著名的报国寺，不时有上下山的行人来来往往。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"bgsgate",
  "southdown" : __DIR__"shijie3",
]));
	set("no_clean_up", 0);

	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",20);
	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",20);
	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
