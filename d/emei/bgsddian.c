inherit ROOM;

void create()
{
	set("short", "报国寺大殿");
	set("long", @LONG
这里是著名的报国寺的大殿，抬头望去，是一尊巨大的如来佛像，俯视
众生。大殿前的蒲团上跪满了善男信女，祈求着菩萨的保佑。两边是金碧辉
煌的盘龙木柱，再边上就是厢房了。庄严的气氛使你也不由自主的想到蒲团
上跪下(kneel)给自己祈福。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"bgsgate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
