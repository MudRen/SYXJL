#include <ansi.h>
inherit ITEM;

void create()
{
     set_name(BLU"蜂巢"NOR, ({
              "fengchao",
              "chao"
             }));
     set_weight(25);
     if (clonep())
     set_default_object(__FILE__);
     else {
     set("unit", "只");
     set("long", 
     "这是一只很大的蜂巢，显然不是普通蜜蜂所造。\n");
     set("value", 100);
     setup();
}
}

