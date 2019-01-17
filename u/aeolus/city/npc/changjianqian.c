inherit NPC;

#include <ansi.h>
void create()
{
  set_name(HIC"����ǰ"NOR, ({"chang jianqian", "chang" }));
  set("title", MAG"��ʦ"NOR);
  set("gender", "����");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("qi", 3000);
  set("max_qi", 3000);
  set("jing", 3000);
  set("max_jing", 3000);
  set("neili", 1000);
  set("max_neili", 1000);
  set("jingli", 1000);
  set("max_jingli", 1000);
  set("force_factor", 80);
  setup();
}

void die ()
{
  object me = this_object();

  message_vision ("\n���´������йٵ�������$N����δ����\n",me);
  message_vision ("\n$N��ΡΡ�شӵ���˦������������\n",me);
  set("qi", 3000);
  set("jing", 3000);
}

void unconcious()
{
  die();
}

void accept_fight (object ob)
{
  object me = this_object();

  message_vision ("$N��æ����˵���Ϸ������࣬���򣬲���Ҳ��\n",me);
}

void kill_ob (object ob)
{
  object me = this_object();

  message_vision ("$N��æ����˵���Ϸ������࣬���򣬲���Ҳ��\n",me);
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
}

int accept_object(object who, object ob)
{


        if (ob->query("money_id") && ob->value() >= 100000) 
                message_vision("����ǰ���˵�˵������λ" + RANK_D->query_respect(ob) +
                "��֪�����⣬\n������ȥ���ϰɣ������ˣ�\n",ob);

     write(HIY "����ǰ��������һƬ�Ʋʣ�\n
     ����ö��߷�����ش���ת�۱����������\n" NOR);
     ob->move("/u/wry/godleitai");

}
