// ROOM heiwu.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "小黑屋");
        set("long", @LONG
四周黑漆漆的一片，你的心中不禁一凉，暗自思量：这是什么
鬼地方？突然你强烈的感觉到在这间小黑屋中肯定存在着什么奇异
的东西，这一切都透着几丝诡异，让人顿生好奇之心，想去仔细寻
找一番！
LONG
        ); 
        set("exits",  ([
               "out" : __DIR__"ymdrk12",
]));        set("no_clean_up", 0);
        setup();
}  
void init()
{
    add_action("do_search", "search");
    this_player()->receive_damage("qi", 500+random(500));
    this_player()->receive_wound("qi",  500+random(500));
message_vision(HIR"突然一阵无比强劲的罡气向$N迎面冲来，$N只觉得胸前好似遭到了千钧重棒的锤击
一般，顿时喘不上气来，全身如同散了架，迅速的倒飞了出去！\n"NOR, this_player());    }
int do_search(string arg)
{
        object ob;

        ob = this_player();
        if( ob->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");
        message_vision("$N仔细的搜寻了这里的每一个角落。\n", ob);
        ob->start_busy(2);
        call_out("search_obj", 4, ob);
        return 1;
} 
int search_obj(object me)
{
        int kar,per;
        int exp;
        object  book, box;

        if(!(this_object()->query("marks/none"))) {
                kar = (int)me->query("kar"); per = (int)me->query("per");                        exp = (int)me->query("combat_exp");
                if( kar > 60 ) kar = 60;
                if( (random(60 - kar) < 5) && (exp >= 100000) && ( kar >= 27 || per >= 36 ))  {
                       this_object()->set("marks/none", 1);
                        message_vision(HIW"$N找到了一个破烂乎乎的小铁箱，放进了怀里。\n"NOR, me);
                        seteuid( geteuid(me));
                        book = new(__DIR__"npc/obj/danuoyi-xinfa1");
                        box = new(__DIR__"npc/obj/box");
                        book->move(box);
                        box->move(me);
                }
                else
                        message_vision("$N什么都没找到。\n", me); 
                        me->add("jing", -15);        }
        else
                message_vision("$N什么都没找到。\n", me);

        return 1;
} 
void reset()
{       ::reset();
        delete("marks/none");
}

