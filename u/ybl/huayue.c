// huayue 花月醉梦 by followme.2000.05

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
          set("no_get", HIR"造反啊!敢拿兰花的东东!"NOR);
          set_name(BLINK HIW"花月醉梦"NOR,({ "huayue", "jian", "sword"}) );
          set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        
        else {
                set("unit", "柄");
                set("wield_msg", HIY"$N右手斜指天边"+HIW"一阵闪电雷鸣过后"+HIY"只见"+BLINK+HIW"花月醉梦"+NOR+HIY"自天边飞来。\n"NOR);
                set("long", "此剑不停的闪动，的确不是人间之物。\n");
                  set("unwield_msg", HIW "$N口念有词，"+HIW"花月醉梦"+HIW"忽然间不见踪影。\n" NOR);               
        }
          init_sword(5000);
        setup();
}


