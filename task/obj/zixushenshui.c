#include <ansi.h>
inherit ITEM;
int do_xh (string arg);
void create()
{
  set_name(HIM"������ˮ"NOR, ({"zixushenshui", "shenshui", "water"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ƿ");
  
  set("long", "һ���Źֵ�ƿ��װ��һЩ��������ͨ��ˮ��������ҥ����
��������Ի���xh��������������ˮ��\n");
    }
    setup();
}
void init()
{
   add_action("do_xh", "xh");
}
int do_xh (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if ((! arg ||
     ! (ob = present(arg, who)))&&
   (! arg || ! (ob = present(arg, where))))
  {
    return notify_fail("��Ҫ����ˮ��ʲô�ã�\n");
  }
  if (ob == who)
  {
    message_vision ("$N������ˮ���Լ�������һ�������䡱��һ�����һ���������ˡ�\n",who);
    message_vision ("��ʱ$Nֻ����һ�ɾ��������������̣�Ǭ�����ã�\n",who);
    who->unconcious();
  }
  else if ((string)ob->query("name") != HIC"���佣"NOR) {

    message_vision ("$N����������ˮ��$n��һ����$n���䡱��һ������������֮�С�\n",who,ob);
  }
  else
  {
   message_vision("$N����������ˮ��$n��һ����$n���䡱��һ������������֮�С�\n
ֻ��$n�Ͻ������ֳ������֣��ƺ���һ�׽��ס�\n",who,ob);
   ob->set("OK_to_STUDY", 1);
  }
  destruct (me);
  return 1;
}

