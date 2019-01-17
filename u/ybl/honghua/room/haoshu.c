// force_book.c 内功心法

inherit ITEM;

void create()
{
        set_name("红花心法", ({ "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long", "这是一本线装书，记载着红花会的内功心法。\n");
                set("value", 0);
		set("material", "paper");
         "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    0,     // jing cost every time study this
                        "difficulty":   0,     // the base int to learn this skill
                        "max_skill":    500      // the maximum level you can learn
		]) );
	}
}
void init()
{
        add_action("do_study", "study");
}
int do_study(string arg)
{
        object me;
        int    jing_cost;
        me = this_player();
        if ( !arg || ( arg != "shu" ) )
                return notify_fail("什么？\n");
        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        jing_cost = (-1) * random(40);
        if((int)me->query("jing") < jing_cost)
                return notify_fail("你现在精神无法集中！\n");
        me->add("jing", jing_cost);
        message_vision("$N正专心研读石桌上的古怪图形。\n", me);
        switch( random(5) ) 
        {
            case 0:
                if ( (int)me->query_skill("finger", 1) < 100)
                {
                        me->improve_skill("finger", me->query("int"));
                        write("你对着石桌琢磨了一回儿，似乎对指法有点心得。\n");
                        me->set_temp("stone_learned",1);
                        me->set_temp("shu                }_learned",1);
            case 1:
                if ( (int)me->query_skill("claw", 1) < 100)
                {
                        me->improve_skill("claw", me->query("int"));
                        write("你对着石桌琢磨了一回儿，似乎对爪法有点心得。\n");
                        me->set_temp("stone_learned",1);
                }
            case 2:
                if ( (int)me->query_skill("strike", 1) < 100)
                {
                        me->improve_skill("strike", me->query("int"));
                        write("你对着石桌琢磨了一回儿，似乎对掌法有点心得。\n");
                        me->set_temp("stone_learned",1);
                }
            case 3:
                if ( (int)me->query_skill("cuff", 1) < 100)
                {
                        me->improve_skill("cuff", me->query("int"));
                        write("你对着石桌琢磨了一回儿，似乎对拳法有点心得。\n");
                        me->set_temp("stone_learned",1);
                }
            case 4:
                if ( (int)me->query_skill("hand", 1) < 100)
                {
                        me->improve_skill("hand", me->query("int"));
                        write("你对着石桌琢磨了一回儿，似乎对手法有点心得。\n");
                        me->set_temp("shu_learned",1);
                }
        }
        if ( !me->query_temp("shu_learned") )
        {
                write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
        }
        return 1;
}
