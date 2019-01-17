#include <ansi.h>

inherit ITEM;

void create()
{
   set_name("����", ({"jiang cha", "jiang","cha"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
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
       return notify_fail("��Ҫ��ʲô��\n");

   message_vision("$N����һ��" + name() + "��\n", me);
   if ((int)me->query_condition("ill_fashao") > 0) {
    if ((int)me->query_condition("ill_fashao") < 11) {
      me->apply_condition("ill_fashao", 0);
      message_vision("$N����ɫ����ȥ�ö��ˡ�\n", me); }
   else {
   me->apply_condition("ill_fashao", (int)me->query_condition("ill_fashao") -10);
      message_vision("$N����ɫ��������������\n", me);
   }
  }
    else tell_object(me, "����û����ޱ����ʡ�\n" NOR );

   destruct(this_object());
   return 1;
}
