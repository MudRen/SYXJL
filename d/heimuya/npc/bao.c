#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("鲍大楚", ({ "bao dachu", "bao",}));
        set("long", 
"一个身材瘦削的老者，依相貌根本看不出他是身怀绝艺的高手。\n");
        set("title",RED"日月神教朱雀堂主"NOR);         
       set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 900);
        set("max_jing", 300);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("shen", -1);


        set_skill("sword", 140); 
        set_skill("parry", 140);
        set_skill("dodge", 140);
        set_skill("unarmed",140);
        set_skill("force",140);
        set_skill("tmzhang",140);
        set_skill("tmjian",140);
        set_skill("tmdao",140);        
        set_skill("pmshenfa",140);
        set_skill("tmdafa",140);
     
   map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
       map_skill("force", "tmdafa");
create_family("日月神教", 3, "弟子");


          set("inquiry", ([
              "疗伤" : (: ask_me :),
        ]));

        setup();
       carry_object("/d/city/npc/obj/gangdao")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();          
}

string ask_me()
{
       mapping fam; 

       object ob;
        ob=this_player();
      write( "鲍大楚正盯著你看，不知道打些什么主意。\n"); 
      if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
               return RANK_D->query_respect(this_player()) + 
               "与本教素无来往，不知此话从何谈起？";
      if ((int)this_player()->query("eff_qi") >= (int)this_player()->query("max_qi")) 
        return RANK_D->query_respect(this_player()) + "气血充足，不用医治啊。";
         
       ob->set("eff_jing", (int)ob->query("max_jing"));
       ob->set("jing", (int)ob->query("max_jing"));
       ob->set("eff_qi", (int)ob->query("max_qi"));
       ob->set("qi", (int)ob->query("max_qi"));
       write( HIW "鲍大楚从百汇给你注入一股内力，你觉得浑身暖洋洋的，好象失去的气血都回到了身上 \n"NOR);

       return "好了你可以走了"; 

}

