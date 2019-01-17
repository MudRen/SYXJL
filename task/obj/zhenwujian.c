#include <weapon.h>
#include <ansi.h>

inherit SWORD;
int do_du(string arg);

void create()
{
        set_name(HIC"真武剑"NOR, ({ "zhenwu jian","jian", "sword"}) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500000);
     set("no_sell", 1);
     set("long", "一把削铁如泥的宝剑，剑刃上似乎刻了一些图画，不知是什么意思。\n");
     set("wield_msg", "$N“铿”地一声，一道寒光闪过，拔出一把$n。\n");
     set("unwield_msg", "$N把$n插回鞘中，嘴角露出一丝笑意。\n");
                set("material", "iron");
        }
        init_sword(160);
        setup();
}


void init()
{
        add_action("do_du", "kan");
}

int do_du(string arg)
{       int gain;
        object me=this_player();
        object ob=this_object();

        if(! ob->query("OK_to_STUDY"))
                return notify_fail("你无法从这样东西上学到任何东西。\n");

        if( (int)me->query_skill("sword", 1) >= 200)
                return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了。\n");
        if( (int)me->query_skill("literate", 1) < 20)
                return notify_fail("可能是你读书识字不精，无法领会上面的图画。\n");

        if( (int)me->query_skill("literate", 1) < (int)me->query_skill("sword", 1) )
                return notify_fail("可能是你读书识字还不深，暂时还领悟不出更深一层的剑法。\n");

        if( (int)me->query("qi") < 30)
                return notify_fail("你太累了，歇歇再来吧。\n");
        if( (int)me->query("jing") < 30)
                return notify_fail("你太疲劳了，歇歇再来吧。\n");
        gain= (int)me->query_skill("literate", 1)/3 + 1 + random((int)me->query_int());

        me->improve_skill("sword", gain);
   me->receive_damage("qi", 30);
   me->receive_damage("jing", 30);

        write("你认真揣摩着真武剑上的图文，似乎对「基本剑法」又有所了解。\n");
        tell_room( environment(me), me->name() +"双眼盯着真武剑，手里还不知在比划什么。\n", ({me}));
        return 1;
}

