inherit ROOM;

void create()
{
        set("short", "仙人洞");
        set("long", @LONG
走过三岔口，首先就看到一座石洞，衣带飘摇，仙风道骨，直似
仙家下界，博览无遗。
LONG
        );
//         set("objects", ([
//                __DIR__"npc/xmabu": 1,]) );

        set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"xianren",
]));
        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_zuan", "zuan");
}

int do_zuan(string arg)
{
        object me,room;
        me = this_player();
        if ( !arg || arg == "") return 0;
        if ( arg != "dong")
                return notify_fail("乌黑吗漆的，你想干嘛？钻去哪里？开山？\n");
//	if ( !me->query_temp("marks/zuan") )
//                return 0;
        if ( !(room== find_object(__DIR__"climb1")) )
                room = load_object(__DIR__"climb1"); 
//	me->delete_temp("marks/zuan");
        message("vision", me->name()+"滋溜一下不知从什么地方钻出去了。\n",environment(me), ({me}) );
        me->move(__DIR__"climb1");
        return 1;
}


