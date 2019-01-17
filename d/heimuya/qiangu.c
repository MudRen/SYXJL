inherit ROOM;

void create()
{
        set("short", "千古石");
        set("long", @LONG
百丈泉边有这一方草坪，草坪中耸立着一块翠绿翠绿的巨石，
传言已有千年之久，石上边缘处不知何人有书红字“千古石”。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"baizhang",
]));
        set("objects", ([
                __DIR__"npc/tufeitou": 1,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}
 
void init()
{
        add_action("do_study", "study");
        add_action("do_study", "du");
}

int do_study(string arg)
{
        object me;
        me = this_player();
        if ( !arg || (arg != "stone" ))
               return notify_fail("什么？\n");
        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        me->receive_damage("jing", 30);
        message_vision("$N正专心研读坪上的石头。\n", me);

        if ( (int)me->query_skill("unarmed", 1) < 101)
        {
                me->improve_skill("unarmed", me->query("int"));
                write("你对着石坪上的「文字」琢磨了一回儿，似乎对基本拳脚有了心得。\n");
                return 1;
        }
        write("你对着石坪瞧了一回儿，发现上面所说的拳脚太过浅显，对你来说已毫无意义了。\n");
        return 1;
}

