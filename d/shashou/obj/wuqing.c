//wuqing.c 无情刀
#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIW "无情刀" NOR, ({ "wuqing dao", "dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把不平凡的刀，刀长三迟七寸，锋刃无瑕，
		一望就知是一把绝世宝刀。\n");
		set("value", 1000000);
                  set("unique", 1);

		set("material", "steel");
		set("no_drop", "这样东西不能离开你。\n");
		set("no_get", "这样东西不能离开那儿。\n");
		set("wield_msg", HIY "只听「铮」的一声，$N缓缓地抽出无情刀，只觉得一种
肃杀之意充盈你的心间。\n" NOR);
		set("unwield_msg", HIY "无情刀自$N掌中飞起，在半空中一转，「唰」地跃入刀鞘。\n" NOR);
	}
        init_blade(150);
	setup();
}
