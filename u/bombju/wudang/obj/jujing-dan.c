// jujing-dan.c 聚精丹

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY"延年聚精丹"NOR, ({"jujing dan","dan"}));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", HIG"这是一颗药香怡人的"HIY"延年聚精丹。\n"NOR);
                set("value", 10000);
                set("no_drop", "这样东西不能离开你。\n");
                set("no_give", "这样东西不能送人。\n");
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        if ( me->query_skill_mapped("force") != "taiji-shengong" )
        {
                if( me->query("max_jingli")>=10)
                {
                   me->add("max_jingli", -10);
                   message_vision(HIR "$N吃下一颗延年聚精丹，只觉得头胀欲裂，原来所练内功不符，反而大损真元！\n" NOR, me);
                   me->unconcious();
                }
                else
                {
                   me->set("max_jingli", 0);
                   message_vision(HIR "$N吃下一颗延年聚精丹，只觉得头胀欲裂，原来所练内功不符，反而大损真元！\n" NOR, me);
                   me->unconcious();
                }
                destruct(this_object());
                return 1;
        }

 if ( me->query("max_jingli") < 150 )
        {
                if( me->query("max_jingli")>1)
                {
                   me->add("max_jingli", -1);
                   message_vision(HIR "$N吃下一颗延年聚精丹，只觉得头重脚轻，摇摇欲倒，原来精力不够，药效适得其反！\n" NOR, me);
                 }
                 else
                 {
                   message_vision(HIR "$N吃下一颗延年聚精丹，只觉得头重脚轻，摇摇欲倒，原来精力不够，药效适得其反！\n" NOR, me);
                   me->unconcious();
                 }

        }
        else if ( (int)me->query_condition("bonze_drug" ) > 0 )
        {
                if( me->query("max_jingli")>1)
                {
                   me->add("max_jingli", -1);
                   message_vision(HIR "$N又吃下一颗延年聚精丹，只觉得肝肠寸断，五脏欲裂，原来服食太急太多，药效适得其反！\n" NOR, me);
                 }
                 else
                 {
                   message_vision(HIR "$N又吃下一颗延年聚精丹，只觉得肝肠寸断，五脏欲裂，原来服食太急太多，药效适得其反！\n" NOR, me);
                   me->unconcious();
                 }
        }
        else
        {
                me->add("max_jingli", random(me->query("kar")*2));
                message_vision(HIY "$N吃下一颗延年聚精丹，只觉得身体飘飘欲仙，顿觉精神百倍！\n" NOR, me);
                me->apply_condition("bonze_drug", 20);
        }
        
        destruct(this_object());
        return 1;
}
