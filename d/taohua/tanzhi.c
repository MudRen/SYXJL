// tanzhi.c 弹指峰

inherit ROOM;

int do_tan(string arg);

void create()
{
	set("short", "弹指峰");
	set("long", @LONG
这里是桃花岛唯一的一座山峰,放眼望去,可鸟瞰整个桃花岛的壮美景观
及辽阔的大海.正中的悬崖壁上有一个巨大的八卦印(bagua).
LONG
	);
	set("exits", ([
              "north" : __DIR__"houyuan",
		 ]));	
	set("item_desc", ([
		"bagua" : "这是一个巨大的八卦印,上面有一些指印,好像是有人有强劲的指力弹上去的。\n",
	]));

	set("coor/x",50);
	set("coor/y",-250);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_tan", "tan");
}


int do_tan(string arg)
{
	object me;
	int    jing_cost;

	me = this_player();

	if ( !arg || ( arg != "bagua" ) )
		return notify_fail("什么？\n");

	jing_cost = (-1) * random(20);
	if((int)me->query("jing") < jing_cost)
		return notify_fail("你现在精神无法集中！\n");

	me->add("jing", jing_cost);
	message("vision",
			me->name() + "对准八卦上的奇怪指印弹了过去。\n",
			environment(me), ({me}) );
	
	if ( (int)me->query_skill("finger", 1) < 101)
	{
		me->improve_skill("finger", me->query("int"));
		write("你屈指对着八卦印弹过去,再琢磨了一回儿，似乎对指法有点心得。\n");
		me->set_temp("bagua_learned",1);
	}
	    

	if ( !me->query_temp("bagua_learned") )
	{
		write("你对着八卦印琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}
	return 1;
}

