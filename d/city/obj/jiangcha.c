#include <ansi.h>

inherit ITEM;

void create()
{
   set_name("姜茶", ({"jiang cha", "jiang","cha"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "碗");
      set("value", 1000);
   }
   setup();
}

int init()
{
   add_action("do_drink", "drink");
   add_action("do_drink", "he");   
}

int do_drink(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("你要喝什么？\n");

   message_vision("$N喝下一碗" + name() + "。\n", me);
   if ((int)me->query_condition("ill_fashao") > 0) {
    if ((int)me->query_condition("ill_fashao") < 11) {
      me->apply_condition("ill_fashao", 0);
      message_vision("$N的脸色看上去好多了。\n", me); }
   else {
   me->apply_condition("ill_fashao", (int)me->query_condition("ill_fashao") -10);
      message_vision("$N的脸色渐渐红润起来。\n", me);
   }
  }
    else tell_object(me, "你觉得浑身无比舒适。\n" NOR );

   destruct(this_object());
   return 1;
}
