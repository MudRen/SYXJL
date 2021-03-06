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
        set_name("灯笼", ({"deng long", "deng","long"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个灯笼，可以在夜间行走的时候用来(use)照明。\n");
                set("value", 1000);
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
        return notify_fail("灯笼已经点燃过了。\n");
        message_vision(HIY "$N点燃了灯笼，一蓬火光一闪，四周顿时亮了起来。\n" NOR, this_player());
        set("used",1);
        me->set_temp("night/light", "灯笼");
        set("no_drop",1);
        call_out("do_used",30+random(5),me);
        return 1;
}

int do_used(object me)
{
        message_vision("$N手中灯笼的火光慢慢地灭了。\n",me);
        me->delete_temp("night/light");
        destruct(this_object());
        return 1;
}       

