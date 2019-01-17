#include <weapon.h>

inherit SWORD;
#include <ansi.h>

void create()
{
   set_name(HIC"七星剑"NOR, ({ "qixing sword", "jian", "sword" }) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("value", 10000);
     set("material", "steel");
     set("long", "这是一把锋利的钨金剑，上面画着天罡北斗七星，因此名曰“七星剑”，是重阳真人的佩剑。\n");
     set("wield_msg", "一道青光闪过，$N手中已多了把$n。\n");
     set("unequip_msg", "$N放下手中的$n。\n");
   }
   init_sword(200);
   setup();
}
