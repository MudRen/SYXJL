
inherit NPC
void create()
{
set_name("倭寇", ({ "devil" }) )
  set("gender", "男性" )
  set("age", 26)
set("str", 22)
set("cor", 30)
 set("cps", 10)
set("int", 10)
  set("per", 5)
set("con", 10)
set("con", set("con", 10)
set("long", "这个倭人身高不到六尺，头着白布带，手举武士刀，两只小眼充
满血丝，正在四处张望，当他发现你正看他时，怪叫一声冲了过来\n")
 set("combat_exp", 1000)
 set("combat_exp", 1000)
 set("attitude", "heroism")
 set("pursuer", 1)
     set("env/wimpy", 70)
set("max_atman", 1000)
 set("max_force", 1000)
 set("max_force", 1000)
    set_skill("unarmed",50)
    set_skill("unarmed",50)
   set_skill("dodge", 70)
   set_skill("force", 30)
 set_skill("blade", 100)
   carry_object("/obj/blade")->wield()
     carry_object("/obj/cloth")->wear()
     add_money("gold", 2)
}
