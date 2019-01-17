inherit ROOM;
void create()
{
	set("short", "东廊");
	set("long", @LONG
这里是两条长廊交汇的地方，往西可到千佛庵大殿，往东就可以出东
侧门到归云阁了，往南往北都是师太们和俗家弟子的禅房了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"dxiang",
  "south" : __DIR__"dlang4",
  "north" : __DIR__"dlang2",
  "east" : __DIR__"dcmen",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
