#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_pai(string arg);
void create()
{
         set("short","水池");
         set ("long",@long
这是一大水池。一阵微风吹过，水中菏叶随风在水面上漂浮, 水面(mian)
碧波涌起，妙不可言。水池中央有一座假山，其中的石洞是很多的，使人
忍不住想探个究竟。
long);
         set("outdoors","mr");
         set("item_desc",([
             "mian" : "水面泛着涟漪，闪烁着点点光亮，几只蜻蜓落在荷花上。\n"
]));
         set("exits", ([
             "west" : __DIR__"xiaojing7",
]));
         set("coor/x",140);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}

void init()
{
        add_action("do_jump", "jump");
//        add_action("do_pai","pai")
//        add_action("do_daji","daji")
        add_action("do_clean","clean");
}

int do_jump(string arg)
               {
                    object me;
               me = this_player();
                  if (arg !="chi")
              return notify_fail("你要到那去？\n");
          
             if (me->query_dex()<17) 
                    write("你试图跳过水池，无奈身法不够敏捷，只好做罢。\n");
            else {
                    write("你纵身跳过了水池,落到了假山上。\n");
                    message("vision",
                             me->name() + "一纵身越过了水池。\n",
                             environment(me), ({me}) );
              me->move(__DIR__"jiashan");
                    message("vision",
                             me->name() + "从水池边跃了上来。\n",
                             environment(me), ({me}) );
                return 1;
           }
}
int do_pai(string arg)
{         object me;
        me = this_player();
 if ( !living(this_player()) || arg != "mian" )
                 return 0;                          
                 if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("你无法在战斗中腾出手来！\n");
                return 1;
        }
        if ((int)me->query_skill("strike", 1) >100 ) {
                write("击打水面已经无法提高你的基本掌法了！\n");
                return 0;
        }
        if ( (int)me->query("jing")<30) {
                           me->receive_damage("jing", 10);
                 write("你太累了，已经没有力气来击打水面了！\n");              
        return 1;
}
me->receive_damage("jing", 15+random(10));
        write("你不时地击打着水面，泛起阵阵涟漪，这是你觉得你的基本掌法有所提高。\n");
        message_vision("$N正在不时地击打着水面，泛起阵阵涟漪。\n", me);  
                    me->improve_skill("strike", me->query("int"));
         return 1;
}                                     

int do_clean(string arg)
{
    object me = this_player();
    object ob;                             
    if (! (ob = present("paper", me)) || userp(ob))
    return notify_fail("你要干什么？\n");
    if (arg != "paper" && arg != "纸卷") 
    return notify_fail("你要干什么？\n");
    write("你不经意的把纸卷丢到水池中。\n",me);
    write("纸卷渐渐干净了，显出了一行行小字。\n", me);
    destruct(ob);
ob = new(__DIR__"npc/obj/paper1.c");
    ob->move(me);
    return 1;
}
