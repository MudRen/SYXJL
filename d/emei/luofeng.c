inherit ROOM;

void create()
{
	set("short", "罗峰山");
	set("long", @LONG
这里就是罗峰山了。放眼望去，是满目的绿树和白云，绿色的树叶和
白色的云交相辉映，看上去象是翠绿的云彩，这就是“罗峰翠云”的由来。
在北边茂密的树林里好象隐隐约约有条小道，但由于满山的“翠云”，却
又看不大清楚。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"fuhusi",
]));
	set("no_clean_up", 0);

	set("coor/x",-50);
	set("coor/y",-40);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-40);
	set("coor/z",20);
	set("coor/x",-50);
	set("coor/y",-40);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
