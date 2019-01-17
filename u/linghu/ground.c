// create by five

inherit ROOM;
inherit __DIR__"ground3";

#include <ground.h>

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������Ǹ߸ߵĹ������̨��ʮ�ɼ����ĳ��������������
����һȦ��ɫ���ʯ�������������Ƶ��ĸ��޴����ͭ������
�����м������ɵ�Ƥ��֯��̺������Ǳ�����(weapon)���ұ�
�Ƿ��߼�(armor)�������Ÿ��������ͻ��ߡ�����ǰѡ�־ʹ�
���������ϸ�ȡ���衣

LONG);

  set("objects", ([
        __DIR__"npc/wei"  : 1,
        __DIR__"npc/siguan"  : 2,
      ]));

  set("item_desc", ([
       "weapon" : @LONG

һ�Ż��̴ľ���Ϸ��Ÿ��ָ����ı�׼�����������
����������ȡ���ֵı������ɴ�̴ľ��������(take)
����,�����Ϸ��У�
  ��師��    axe
  �ֵ���      blade
  �ֲ棺      fork
  ��ǹ��      spear
  ���ȣ�      staff
  ��������    club
  ������      sword
  ���ʯ��    throwing
  Ƥ�ޣ�      whip
  ذ�ף�      dagger
  ������      hammer

LONG,

      "armor" :@LONG

һ������̴ľ���Ϸ��Ŵ��СС�ı�׼���׻��ߣ���
�������������ȡ���ʵĿ��׻��ߡ���̴ľ����
����(pick)����,�����Ϸ��У�
  ���ף�      armor
  ���ƣ�      shield
  ѥ�ӣ�      boots
  ָ�ף�      finger
  ���ף�      hands
  ͷ����      head
  Χ����      neck
  ���磺      surcoat
  ������      waist
  ����      wrists

LONG,

      ]));
  set("broadcast",1);
  set("alternative_die",1);
  setup();
}

void init ()
{
  object who = this_player();

  if (wizardp(who))
  {
    init0();
    init1();
    init2();
    init3();
    call_out ("hinting",1,who);
  }
  add_action ("do_hit","fight");
  add_action ("do_hit","kill");
  add_action ("do_hit","hit");
  add_action ("do_quit","quit");
  add_action ("do_take","take");
  add_action ("do_pick","pick");
}
int do_quit()
{ 
  say(" ���ﲻ���˳���\n");
  return 1;
}
int do_pick (string arg)
{
  object who = this_player();
  object ob;

  if (who->query_temp("get/armor") && !wizardp(who))
    return notify_fail ("�Բ���������ʦ�������ö�����\n");

  if (! arg)
    return notify_fail ("��Ҫ��ʲô��\n");
  if (arg == "armor")
    ob = new (__DIR__"obj/armor/armor");    
  else if (arg == "shield")
    ob = new (__DIR__"obj/armor/shield");    
  else if (arg == "boots")
    ob = new (__DIR__"obj/armor/boots");    
  else if (arg == "finger")
    ob = new (__DIR__"obj/armor/finger");    
  else if (arg == "hands")
    ob = new (__DIR__"obj/armor/hands");    
  else if (arg == "head")
    ob = new (__DIR__"obj/armor/head");    
  else if (arg == "neck")
    ob = new (__DIR__"obj/armor/neck");    
  else if (arg == "surcoat")
    ob = new (__DIR__"obj/armor/surcoat");    
  else if (arg == "waist")
    ob = new (__DIR__"obj/armor/waist");    
  else if (arg == "wrists")
    ob = new (__DIR__"obj/armor/wrists");    
  else
    return notify_fail ("��Ҫ��ʲô��\n");
 
  message_vision ("$N�Ӽ���������$n��\n",who,ob);
  ob->move(who);
   who->set_temp("get/armor",1);
  return 1;
}
int do_take (string arg)
{
  object who = this_player();
  object ob;

  if (who->query_temp("get/weapon") && !wizardp(who))
    return notify_fail ("�Բ���������ʦ�������ö�����\n");
  if (! arg)
    return notify_fail ("��Ҫ��ʲô��\n");
  if (arg == "axe")
    ob = new (__DIR__"obj/weapon/axe");    
  else if (arg == "blade")
    ob = new (__DIR__"obj/weapon/blade");    
  else if (arg == "dagger")
    ob = new (__DIR__"obj/weapon/dagger");    
  else if (arg == "fork")
    ob = new (__DIR__"obj/weapon/fork");    
  else if (arg == "hammer")
    ob = new (__DIR__"obj/weapon/hammer");    
  else if (arg == "spear")
    ob = new (__DIR__"obj/weapon/spear");    
  else if (arg == "staff")
    ob = new (__DIR__"obj/weapon/staff");    
  else if (arg == "stick")
    ob = new (__DIR__"obj/weapon/stick");    
  else if (arg == "sword")
    ob = new (__DIR__"obj/weapon/sword");    
  else if (arg == "throwing")
    ob = new (__DIR__"obj/weapon/throwing");    
  else if (arg == "whip")
    ob = new (__DIR__"obj/weapon/whip");    
  else
    return notify_fail ("��Ҫ��ʲô��\n");
  message_vision ("$N�Ӽ���������$n��\n",who,ob);
  ob->move(who);
  who->set_temp("get/weapon",1);
  return 1;
}

int check_fighters (object who, object ob)
{
  object *inv = all_inventory (environment(who));
  object wei = present ("gong pingzi", environment(who));
  string names = "";
  int i = sizeof (inv);

  if (ob == wei)
    return 0;

  while (i--)
  {
    if (inv[i]==who || inv[i]==ob || inv[i]==wei)
      continue;
    if (inv[i]->is_fighting())
      names += inv[i]->name();
  }
  if (names != "")
  {
    message_vision ("$N��$n˵�����ⳡ��"+names+"������������ɱ�����Ժ�Ƭ�̣�\n",wei,who);
    return 0;
  }
  if (! userp(who) || ! userp(ob))
    return 1;
  call_out ("wait_and_announce",1,who,ob);
  return 1;
}

void wait_and_announce (object who, object ob)
{
  mapping match = this_room()->query("match");
  int step;
  string name0, name1, names;

  if (! match)
    return;
  step = match["step"];
  if (step != STEP_FIGHT)
    return;
  if (! who || ! ob)
    return;
  name0 = who->query("name");
  name1 = ob->query("name");
  if (strcmp(name0,name1) > 0)
    names = name0 + name1;
  else
    names = name1 + name0;
  if (match["fighters"] == names)
    return;

  match["fighters"] = names;
announce (name0 + "��" + name1 + "�����������ಫ��\n");
}

int do_hit()
{
  say("���õ���ʦ���\n");
  return 1;
}
void hinting (object who)
{
  tell_object (who, "\n");
  tell_object (who, "����������������������������\n");
  tell_object (who, "����ֳﱸ�������������Ƚ׶Σ���ͬ�׶��в�ͬ�����\n");
  tell_object (who, "��ʹ������ʱ��ע���Ƿ���������ʦҲ�ڴ����ñ������ݡ���\n");
  tell_object (who, "�󡡡�������������������������������������������������\n");
  tell_object (who, "��������ʱʹ�� ? �� what ����ѯ������ʹ�õ���� ����\n");
  tell_object (who, "����������������������������\n");
  tell_object (who, "\n");
}


