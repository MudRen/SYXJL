inherit NPC;

#include <ansi.h>
void create()
{
  set_name(HIC"常剑前"NOR, ({"chang jianqian", "chang" }));
  set("title", MAG"天师"NOR);
  set("gender", "男性");
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

  message_vision ("\n地下传来崔判官的声音：$N阳寿未尽！\n",me);
  message_vision ("\n$N颤巍巍地从地上甩袖爬将起来。\n",me);
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

  message_vision ("$N连忙跳开说：老夫筋骨已朽，不打，不打也！\n",me);
}

void kill_ob (object ob)
{
  object me = this_object();

  message_vision ("$N连忙跳开说：老夫筋骨已朽，不打，不打也！\n",me);
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
}

int accept_object(object who, object ob)
{


        if (ob->query("money_id") && ob->value() >= 100000) 
                message_vision("常剑前高兴地说道：这位" + RANK_D->query_respect(ob) +
                "真知我心意，\n我送你去天上吧，看好了！\n",ob);

     write(HIY "常剑前念动咒语，招来一片云彩，\n
     你觉得耳边风呼呼地吹，转眼便来到了天界\n" NOR);
     ob->move("/u/wry/godleitai");

}
