inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY "转档专用" NOR, ({"baobao"}));
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                   set("unit", "个");
                   set("long", "一个转档专用的物品。\n");
                set("value", 800000);
        }

        setup();
}

void init()
{
        add_action("do_eat", "eat");
       
}

int do_eat(string arg)
{
        if (!id(arg))
         return notify_fail("你要吃什么？\n");
         this_player()->set("mud_age",864000);
         this_player()->add("combat_exp",100000);
           this_player()->set("potential",8000);
         destruct(this_object());
        return 1;
}

