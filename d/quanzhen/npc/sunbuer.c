//sunbuer.c 孙不二

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("孙不二", ({"sun buer", "sun", "buer"}));
        set("nickname", HIB"清静散人"NOR);
        set("gender", "女性");
        set("age", 39);
        set("long",
             "她明目皓齿，肤色白腻，虽穿一身灰色道袍，也掩盖不了她的姿色。\n"
             "她就是全真七子中唯一的女性“清静散人”孙不二。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 29);
        set("int", 32);
        set("con", 30);
        set("dex", 32); 
        set("per", 25);
        set("chat_chance", 1);
        set("chat_msg", ({
                "孙不二说道：“非本教第子不要乱走。”\n",
//        (: random_move :),
        }));

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 1250);
        set("max_jing", 1250);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
        
        set("combat_exp", 1800000);
        set("score", 50000);
 
        set_skill("force", 180);             // 基本内功
        set_skill("tiangang-zhengqi", 180);    //天罡正气
        set_skill("unarmed", 180);           // 基本拳脚
        set_skill("kongming-quan", 140);    //空明拳 
        set_skill("dodge",180);              // 基本躲闪
        set_skill("qixing-huanwei", 180);        //七星换位
        set_skill("parry", 180);             // 基本招架
        set_skill("sword", 180);             // 基本剑法
        set_skill("quanzhen-jianfa", 180);        //天罡剑法 
        set_skill("taoism", 180);            //道学心法  
       set_skill("literate",180);           //读书写字
        set_skill("qixing-array",200); 
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教",2,"长老");
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );


        
        setup();
     
       carry_object("/d/quanzhen/obj/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();

}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="sun buer")
       {
         command("chat "+ob->query("name")+"! 你杀人越货胡作非为，我教岂能容你，从今以后你好自为知吧。。。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","全真教" + RED + "弃徒" NOR);        }
}               


void attempt_apprentice(object ob)
{
     mapping fam = ob->query("family");
      if (!fam || fam["family_name"] != "全真教"){
                command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                return;
                }       
      if((int)ob->query_skill("tiangang-zhengqi", 1) < 80) {
                command("say 我全真教武功内功是基础。"); 
                command("say " + RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
                return;
                }  
      if((int)ob->query_skill("sword", 1) < 80) {
                command("say 你剑法这么差，我教的你不一定学得会。"); 
                command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                return;
                }
      if(ob->query_int() < 23) {
                command("say 我的武功都要教高的悟性才能学会。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
                command("say 这位"+RANK_D->query_respect(ob)+"的悟性还大有潜力可挖，还是请回吧。");
                return;
                }
      if(ob->query("gender") != "女性") {
                command("say 我可只收女徒，你去找我师兄们试试吧。");
                return;
                }
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("recruit " + ob->query("id"));
        ob->set("title","全真教清静散人爱徒");
        ob->set("class","sworder");
}

