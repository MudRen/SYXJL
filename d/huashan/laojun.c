// laojun.c

inherit ROOM;

void create()
{
	set("short", "老君沟");
	set("long", @LONG
爬过两个要命的悬崖，可在这里稍作歇息。老君沟是一条半里多长的
山沟，相传为太上老君所开，故名老君沟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"baichi",
		"southup" : __DIR__"husun",
	]));

	set("objects", ([ 
		__DIR__"npc/laodenuo" : 1,
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x",70);
	set("coor/y",110);
	set("coor/z",40);
	set("coor/x",70);
	set("coor/y",110);
	set("coor/z",40);
	set("coor/x",70);
	set("coor/y",110);
	set("coor/z",40);
	set("coor/x",70);
	set("coor/y",110);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}