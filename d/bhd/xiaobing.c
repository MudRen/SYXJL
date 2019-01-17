inherit ROOM;

void create()
{
        set("short", "小冰块");
        set("long", @LONG
这是一块小浮冰，能用手脚划动它，不远之处就是一块岩石，从
那里可以登上陆地。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"bingshan2",
]));
        set("no_clean_up", 0);

        setup();
}

void init()
{
          add_action("do_tiao", "tiao");
}
int do_tiao(string arg)
{
        object ob;
        int new_jing;
        ob = this_player();
        new_jing = random( ob->query("max_jing")*3 );
        if ( new_jing > ob->query("jing") ) new_jing = ob->query("jing") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "yanshi" )
                return notify_fail("你不要跳了，要自杀？用suicide -f快一点：P！\n");
        if( (ob->query("dex") < 20) && ((int)ob->query_skill("dodge")<30) )
                return notify_fail("以你现在的身手，跳上岩石去只有死路一条！\n");
       message_vision("$N毫不考虑，深深的吸了一口气，一个纵身，跳了上去。\n", ob);
       environment(ob), ({ob});
       message_vision("$N空中变换身形，一个空翻，轻飘飘地落在岩石上！\n", ob);
       environment(ob), ob;  
       ob->add("jing", 0 - new_jing);
	ob->move("/d/bhd/yanshi");
       return 1;
}



