#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "杂货室");
        set("long", @LONG
这里是曼佗罗山庄的杂货室，里面摆满了各种不用的旧物品，在杂货室
的一角摆放着一个兵器架(jia)。
LONG    );
        set("exits", ([ 
                "west" : __DIR__"hhyuan",
                "east" : __DIR__"c14-5",
        ]));
                set("item_desc", ([ 
"jia" : "兵器架放着各式各样的兵器：
一次只能拿一件。
        钢剑(jian)           铁甲(armor)        钢杖(gangzhang)
        长剑(changjian)      长鞭(changian)     竹剑(zhujian)
        短剑(duanjian)       钢刀(blade)        竹棒(zhubang)
        竹剑(zhujian)        

你可以拿(na)一样做你武器。
\n"
]));
        set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();

}

void init()
{
        add_action("do_na","na");
}

int do_na(string arg)
{
        mapping fam; 
        object me;
        me=this_player();
        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "姑苏慕容")
                return notify_fail("除了慕容弟子外，外人是不能在这取兵器的！！\n");

        if (me->query_temp("marks/拿1") )
                return notify_fail("你已拿了兵器，还要拿吗？！\n");

        if (arg=="all from jia") 
                return notify_fail("你怎么要拿么多兵器呀，拿去变卖？！\n");

        if (!arg) return notify_fail("你要拿什么兵器？\n");

        if (!"jian from jia"||!"changjian from jia"||!"duanjian from jia"
||!"zhujian from jia"||!"changbian from jian"||!"blade from jia"
||!"dao from jia"||!"armor from jia") return 0;

        if (arg=="jian from jia"){
        message_vision("$N从兵器架里拿出一把钢剑。\n",me);
        this_player()->set_temp("marks/拿1", 1);
        me = new("/d/city/obj/gangjian");
        me->move(this_player());
        return 1;
        }
        
        if (arg=="changjian from jia"){
        message_vision("$N从兵器架里拿出一把长剑。\n",me);
        this_player()->set_temp("marks/拿1", 1);
        me = new("/d/city/obj/changjian");
        me->move(this_player());
        return 1;
        }

        if (arg=="duanjian from jia"){
        message_vision("$N从兵器架里拿出一把短剑。\n",me);
        this_player()->set_temp("marks/拿1", 1);
        me = new("/d/city/obj/duanjian");
        me->move(this_player());
        return 1;
        }

        if (arg=="zhujian from jia"){
        message_vision("$N从兵器架里拿出一把竹剑。\n",me);
        this_player()->set_temp("marks/拿1", 1);
        me = new("/d/village/obj/zhujian");
        me->move(this_player());
        return 1;
        }
        
        if (arg=="blade from jia"){
        message_vision("$N从兵器架里拿出一把钢刀。\n",me);
        this_player()->set_temp("marks/拿1", 1);
        me = new("/d/city/obj/gangdao");
        me->move(this_player());
        return 1;
        }

        if (arg=="dao from jia"){
        message_vision("$N从兵器架里拿出一把木刀。\n",me);
        this_player()->set_temp("marks/拿1", 1);
me = new("/u/beyond/mr/obj/mudao");
        me->move(this_player());
        return 1;
        }

        if (arg=="changbian from jia"){
        message_vision("$N从兵器架里拿出一条长鞭。\n",me);
        this_player()->set_temp("marks/拿1", 1);
        me = new("/d/xingxiu/npc/obj/changbian");
        me->move(this_player());
        return 1;
        }
        if (arg=="armor from jia"){
        message_vision("$N从兵器架里拿出一件铁甲。\n",me);
        this_player()->set_temp("marks/拿1", 1);
        me = new("/d/city/obj/tiejia");
        me->move(this_player());
        return 1;
        }
      
        if (arg=="zhubang from jia"){
        message_vision("$N从兵器架里拿出一件竹棒。\n",me);
        this_player()->set_temp("marks/拿1", 1);
        me = new("/d/city/obj/zhubang");
        me->move(this_player());
        return 1;
        }

        if (arg=="gangzhang from jia"){
        message_vision("$N从兵器架里拿出一件钢杖。\n",me);
        this_player()->set_temp("marks/拿1", 1);
        me = new("/d/city/obj/gangzhang");
        me->move(this_player());
        return 1;
        }
}
