// by mayue


inherit ROOM;

void create()
{
	set("short", "黑森林");
	set("long", @LONG
这里就是有名的黑森林，四周均是茂密的丛林，巨大的古木遮
天蔽日，头顶看不到一片天空。脚下不时传来轻微的声响，似乎有
什么东西从草丛中游过，远处偶尔传来一阵野兽的嚎叫声。
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"milin3",
		"south" : __DIR__"milin1",
		"west" : __DIR__"milin1",
		"north" : __DIR__"milin2",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));

	setup();
	replace_program(ROOM);
}

