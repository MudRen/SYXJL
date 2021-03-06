// Room: cjlou.c

inherit ROOM;

void create()
{
	set("short", "藏经阁一楼");
	set("long", @LONG
不愧为佛法的总源，此处藏经之富，天下罕有其
匹。这里都是密密麻麻，高及顶棚的书架，书架间仅有容身一人
通行的空隙。几排大书架中间，间隔地放着数丈长的书桌。目光
及处，你看到桌上放了几本佛经。
LONG
	);

	set("exits", ([
		"out" : __DIR__"zoulang3",
		"up" : __DIR__"cjlou1",
	]));

	set("objects",([
		__DIR__"obj/fojing1" : 1,
		__DIR__"obj/fojing2" : 1,
	]));
	setup();
}

