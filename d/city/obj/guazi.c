// kaoya.c 烤鸭

inherit ITEM;
inherit F_FOOD;

void create()
{
      set_name("瓜子", ({"guazi"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
               set("long", "一包瓜子,聊天的时候可以边吃边聊。\n");
         set("unit", "包");
          set("value", 100);
           set("food_remaining", 10);
       set("food_supply", 5);
	}
}
