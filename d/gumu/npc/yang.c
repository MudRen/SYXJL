//yang.c 杨过
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("杨过",({"yang guo","yang","guo"}));
        set("title","古墓侠侣");
        set("nickname",HIY"神雕大侠"NOR);
        set("long", "他就是名满天下的杨过。虽断一臂但仍遮不去一脸的英雄豪气。\n");
        set("age", 35);
        set("attitude", "friendly");
        set("shen", 1000000);
        set("per", 30);
        set("str", 28);
        set("int", 28);
        set("con", 30);
        set("dex", 29);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("eff_jingli", 3000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 2000000); 
        set_skill("sword",200);
        set_skill("dodge",200);
          set_skill("unarmed",200);
          set_skill("cuff",200);
        set_skill("strike",200);
        set_skill("force", 200);
        set_skill("yunu-shenfa", 200);
        set_skill("xuantie-jianfa", 200);
        set_skill("anran-xiaohunzhang", 200);     
        set_skill("quanzhen-jianfa",180);
        set_skill("tianluo-diwang", 180);
        set_skill("parry", 200);
        set_skill("yunu-xinjing",200);
        set_skill("literate", 150); 
        map_skill("force", "yunu-xinjing");        
        map_skill("sword","xuantie-jianfa");
        map_skill("dodge", "yunu-shenfa");
        map_skill("parry", "anran-xiaohunzhang");        
        map_skill("strike", "anran-xiaohunzhang");        
        prepare_skill("strike","anran-xiaohunzhang");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "sword.haichao" :),
        }));
    
        create_family("古墓派",3,"男主人");
        set("inquiry", ([
           "古墓" : "那日华山与众英雄诀别后和龙儿隐居于此已有数年，不闻世事，能与
龙儿在此长伴一世，此身足矣！",
           "玄铁剑" : "玄铁剑乃吾昔日随身之物，此剑杀气甚重，吾无意让此剑重现江湖，
故秘藏此剑于一处。",
           "小龙女" : "龙儿乃我爱妻，你问她做甚？",
        ]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/gumu/obj/buxue1")->wear();
        carry_object("/d/gumu/obj/pao1")->wear();         
}

void attempt_apprentice(object ob)
{
     mapping fam = ob->query("family");
      if (!fam || fam["family_name"] != "古墓派"){
                command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                return;
                }       
      if((int)ob->query_skill("yunu-xinjing", 1) < 120) {
                command("say 内功是古墓武功之基础。"); 
                command("say " + RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
                return;
                }   
      if((int)ob->query_int() < 30 ) {
                command("say 我的武功都要极高的悟性才能学会。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
                command("say "+RANK_D->query_respect(ob)+"的悟性还大有潜力可挖，还是请回吧。");
                return;
                }
      if(ob->query("gender") != "男性") {
                command("say 我可只收男徒，你去找吾妻龙儿试试吧。");
                return;
                }
        command("say 嗯，看你还是个学武的料，我就收下你吧！");         
        command("chat 古墓武功重现江湖，"+ ob->name() +"可别让为师看走眼了！");
        command("chat* pat " + ob->query("id"));
        command("recruit " + ob->query("id"));
        ob->set("title","古墓派神雕侠侣传人");
        ob->set("class","sworder");
}

void leave()
{
   message("vision", name() + "失望的看了看，伤心的走了。\n", environment(), this_object() );
   destruct(this_object());
}

void relay_whisper(object me, string msg)
{
   if (query("owner_id") != me->query("id"))
   {
     message_vision((string)this_object()->query("name") 
        + "对着$N冷哼了一声。\n", me);
     return;
   }
   
   message_vision((string)this_object()->query("name") + "对着$N点了点头。\n", me);
   if (msg)
   {
     remove_call_out ("relaying");
     call_out ("relaying", 1+random(3), msg);
   }
}

void relaying (string msg)
{
   command (msg);
}

void init()
{       
   object me=this_player();
   object owner;

   ::init();

   if ( (string)this_object()->query("owner_id") == (string)me->query("id") )
   {
     this_object()->set_leader(me);
   }

   if( this_object()->query("owner_id") != 0 )
   {
     owner = find_player( (string)this_object()->query("owner_id") );
     if( !owner ) owner=find_living( (string)this_object()->query("owner_id") );
     if( !owner )
     {
        remove_call_out ("leave");
        call_out ("leave", 1);
     }
   }
}
