
inherit NPC
void create()
{
set_name("����", ({ "devil" }) )
  set("gender", "����" )
  set("age", 26)
set("str", 22)
set("cor", 30)
 set("cps", 10)
set("int", 10)
  set("per", 5)
set("con", 10)
set("con", set("con", 10)
set("long", "���������߲������ߣ�ͷ�Űײ������־���ʿ������ֻС�۳�
��Ѫ˿�������Ĵ�����������������������ʱ���ֽ�һ�����˹���\n")
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
