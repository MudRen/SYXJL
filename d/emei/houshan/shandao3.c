// Room: /u/cuer/emei/shandao3.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条山中小道，道上人迹罕至，小道在这里分出三岔，往西南通
向千佛庵后门，往东南通向药王洞，往北就是静修庵了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"shandao4",
  "north" : __DIR__"jxan",
  "southwest" : __DIR__"shandao1",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",120);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",120);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
