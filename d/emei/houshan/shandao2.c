inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条山中小道，道上人迹罕至，小道在这里分出三岔，往东西南
通向千佛庵后门，往西南通向九老洞，往北就是去云海和金顶的路了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"shandao",
  "northwest" : __DIR__"yhrkou",
  "southwest" : __DIR__"xiaojin1",
]));
	set("no_clean_up", 0);

	set("coor/x",-50);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",110);
	set("coor/z",110);
	set("coor/x",-50);
	set("coor/y",110);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
