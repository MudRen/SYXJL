#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("一灯大师",({"yideng dashi","yideng","dashi"}));
    set("nickname", HIY "南帝" NOR );
    set("title", "天龙寺前任主持");
    set("gender", "男性");
    set("age", 42);
    set("long", 
 "他就是天龙寺的开山祖师，当年由于淡泊名利，放弃了帝位，就出家来当了和尚，\n");
    set("attitude", "peaceful");
    set("str", 45);
    set("int", 40);
    set("con", 50);
    set("dex", 40);

    set("inquiry", ([
        "王重阳"   : "王真人才是当世第一高手，当年与老衲互换武功，就是为了要消灭妖孽。 \n",
        "六脉神剑谱" : "光读又有何用？哈哈哈...还是跟我好好学吧！！！\n",
        "拜师" :"我已经让枯荣去给我找弟子去了，你去找他问问好了。",
]));
        set("max_qi", 10000);
      set("qi",10000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jiali", 600);
        set("combat_exp", 3000000);
        set("score", 4000000);

      set_skill("force", 300);             
      set_skill("finger", 250);            
      set_skill("kurong-changong", 300);   
      set_skill("dodge", 250);             
      set_skill("tiannan-bufa", 250);    
      set_skill("parry", 250);             
      set_skill("yiyang-zhi", 250);        
      set_skill("literate",250);
      set_skill("sword", 250); 
      set_skill("duanjia-jian", 250);     
      set_skill("liumai-shenjian", 250); 
      set_skill("jinyu-quan", 250);
      set_skill("unarmed", 250);      
      set_skill("buddhism", 300);
      set_skill("literate", 200);
      map_skill("unarmed" , "jinyu-quan");
      map_skill("force"  , "kurong-changong");
      map_skill("sword", "duanjia-jian");
      map_skill("finger" , "liumai-shenjian");
      map_skill("dodge"  , "tiannan-bufa");
      map_skill("parry"  , "liumai-shenjian");
      map_skill("finger","liumai-shenjian");
      prepare_skill("finger","liumai-shenjian");
  
      create_family("天龙寺", 4, "主持");
     
      set("chat_chance_combat", 100);
      set("chat_msg_combat", ({
                (: perform_action, "finger.tan" :),
                (: perform_action, "finger.feng" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.liujian" :),
                (: exert_function, "recover" :),
        }) );
     setup();
    carry_object(__DIR__"obj/sengxie")->wear();
    carry_object(__DIR__"obj/sengrobe")->wear();

}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 200 && ob->query("family/master_id")=="yideng dashi")
        {
                command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","天龙寺" + RED + "弃徒" NOR);
        }
}

void attempt_apprentice(object ob)
{
        string name,new_name; 
        if((!ob->query("family") || ob->query("family")["family_name"]!="天龙寺"))
        {
                command("say 你非天龙弟子，请恕老衲不能收你。");
                
                return ;
        } 
        if ((string)ob->query("class") != "bonze") {
                command("say 老衲不收俗家弟子，施主请回吧。");
                
                return ;
        }        if ((int)ob->query_skill("kurong-changong", 1) < 220) {
                command("say 我天龙寺着重内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在枯荣禅功上多下点功夫？");
                return ;
        } 
        if ((int)ob->query("score") <500) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }        if ((int)ob->query("shen") <700000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        if ((int)ob->query_skill("buddhism", 1) < 230) {
                command("say 悟禅之人，德义为先，我天龙寺乃佛门嫡传，你先学好佛家的经书吧。");
                command("say 在禅宗心法方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return ;
        }
        if ((int)ob->query_skill("yiyang-zhi", 1) < 200) {
                command("say 本门的六脉神剑乃是以段家一阳指为基础的。");
                command("say 看来，" + RANK_D->query_respect(ob) +
                        "你的一阳指还不够火候。");
                return ;
        } 
        if((string)this_player()->query("family/master_id")!="ku rong" )
        {
                command("say 你还是先去找枯荣师侄学习吧。\n");      
                return ;
        }                                     
        command("say 好啦,起来...你今后可得多多用功");
        command("party 老僧又收一徒弟,大家以后好好切磋。");
        command("recruit " + ob->query("id"));
        name = ob->query("name");     
        new_name = "枯" + name[2..3];
        ob->set("name", new_name);
        command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为天龙寺枯字辈弟子 !");
        
        return ;
}
