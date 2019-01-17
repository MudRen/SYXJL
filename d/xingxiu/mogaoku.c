inherit ROOM;

void create()
{
        set("short", "莫高窟");
        set("long", @LONG
这里墙壁上绘制着与佛教相关的画面(picture)，有仙女飞天，还有反弹琵琶。
洞中还有很多佛像和经书。你被这些瑰丽的文化之宝惊呆了。
LONG
        );
        set("exits", ([ 
             "north" : __DIR__"yueerquan",
]));

        set("item_desc", ([
                "picture" : read_file("/u/csy/photo")
// snicker csy xixi:)
        ]) );

        set("no_clean_up", 0);

        setup();
}
/*
void init()
{
        if (!this_player()->query_temp("think_times"))
                this_player()->set_temp("think_times",
                        7+random(this_player()->query_skill("literate", 1)/10));
        add_action("do_think", "think");
}
*/
int do_think(string arg)
{
        object me = this_player();
                
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");

	if ( !arg || arg != "picture" )
		return notify_fail("你想思索什么？\n");

	if ( me->query("int")+(int)me->query_skill("literate",1)/10 < 42 )
		return notify_fail("你的悟性太低，无法领悟飞天仙女图的涵义。\n");
	
        if ( (int)me->query("jing")<20)
                return notify_fail("你太累了，歇会再想吧！\n");

	if ( (int)me->query_skill("qimen-dunjia", 1) > 130 )
		return notify_fail("你对着飞天仙女图冥思苦想，发现没有什么值得领悟的了。\n");

	if ( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("你的潜能已经发挥到极限，无法领悟飞天仙女图的涵义。\n");

        if ( me->query_temp("think_times") == 0 )
        {
                tell_object(me,"你对着飞天仙女图冥思苦想，忽觉胸中气血翻滚，“哇”的一声吐出一大口鲜血...\n");
                message("vision",me->name()+"忽然“哇”的一声吐出一大口鲜血，晕了过去。\n",environment(me),me);
                me->set_temp("think_times", 7+random(me->query_skill("literate", 1)/10));
                me->unconcious();
                return 1;
        }

       if (!me->query_skill("qimen-dunjia",1))
              me->set_skill("qimen-dunjia",0);
        me->add_temp("think_times", -1);
        me->add("jing", -(10+random(15)));
        me->add("learned_points", 1);
        me->improve_skill("qimen-dunjia", random((int)me->query_skill("literate", 1)/2)+1);
	
	tell_object(me, "你对着飞天仙女图冥思苦想，冥冥中似乎若有所悟...\n你的奇门遁甲进步了！\n");
	message("vision",me->name()+"对着飞天仙女图怔怔的发呆，不知道在干什么。\n", environment(me), me);

        return 1;
}
