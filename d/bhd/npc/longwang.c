// longwang.c 紫杉龙王
// by tony  97/7
#include <ansi.h>
inherit NPC;

object ob = this_object();
void create()
{
        set_name("黛绮丝",({"dai qisi","dai","longwang"}));
        set("title","明教护教法王");
        set("long", 
                "她就是明教的四大护教法王的大姐姐。\n"
                "她一身深紫色罗裙，枭动生姿，青丝及腰，玉颊生春。虽然人到中年，仍然风味犹存。\n");
        set("age", 43);
        set("nickname",MAG"紫杉龙王"NOR);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 32);
        set("con", 20);
        set("dex", 30);
        
        set("max_qi",2000);
        set("max_jing", 1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 60);
          set("combat_exp", 400000);
    

        set_skill("sword",100);
        set_skill("dodge",100);
        set_skill("unarmed",100); 
        set_skill("literate",100);
        set_skill("force",100);
        set_skill("shenghuo-shengong",100);
        set_skill("qingfu-shenfa", 100);
        set_skill("liehuo-jian",100);
        set_skill("blade",100);
        //set_skill("shenghuo-quan",100);  

        map_skill("dodge", "qingfu-shenfa");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        //map_skill("unarmed","shenghuo-quan");

        create_family("明教",34,"弟子");
        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query("int") < 24) {
                command("say " + RANK_D->query_respect(ob) +
                        "天资欠聪，难学得我这一身武功。");
  return;
}
        if ((int)ob->query("dex") < 20) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
 }
         command("say 哈哈！ 我明教又得一良材，望你日后康扶正义，把我明教发扬光大。");
        command("recruit " + ob->query("id"));
        ob->set("title","明教紫衫龙王座下弟子");
}
