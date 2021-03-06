// denglong 灯笼

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_use", "use");
}

void create()
{
        set_name("火把", ({"huo ba", "huo"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个火把，可以在夜间行走的时候用来(use)照明。\n");
                set("value", 500);
                set("unique", 1); 
        }
        setup();
}

int do_use(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要用什么东西？\n");
        if (query("used"))
        return notify_fail("火把已经点燃过了。\n");
        message_vision(HIY "$N点燃了火把，只见火光一闪，四周顿时亮了起来。\n" NOR, this_player());
        set("used",1);
        me->set_temp("night/light", "火把");
        set("no_drop",1);
        call_out("do_used", 15+random(5), me);
        return 1;
}

int do_used(object me)
{
        message_vision("一阵风吹来，把$N手中的火把给吹灭了。\n",me);
        me->delete_temp("night/light");
        destruct(this_object());
        return 1;
}       

