// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
       set_name(HIR"���ϲ��"NOR, ({"tang"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
                  set("long"," һ�����ϲ�ǡ�\n");
         set("unit", "��");
            set("value", 300);
           set("food_remaining", 10);
       set("food_supply", 5);
	}
}
