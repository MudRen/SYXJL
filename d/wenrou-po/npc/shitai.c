//shitai.c ....angle

inherit NPC;

#include <ansi.h>



void create()

{       set_name("温柔师太", ({ "wenrou shitai", "shitai" })); 

        set("title", HIW"温柔庵主持"NOR);        

        set("gender", "女性");

        set("age", 32);

        set("str", 20);

        set("dex", 20); 

        set("per", 30);   

set("long", "这就是远近闻名的温柔师太，据说她遁入佛门的原因就是因为她的绝世佳容，唉……自古红颜祸水,

确实说得不错！\n");

        set("combat_exp", 12000);

        set("shen_type", 1);

        set("attitude", "friendly"); 

       

        set_skill("unarmed", 45);

        set_skill("dodge", 45);

        set_skill("parry", 45);

        set_skill("force", 45);



        set_temp("apply/attack", 25);

        set_temp("apply/defense", 25);

        set_temp("apply/armor", 25);

        set_temp("apply/damage", 15);

        setup();

        carry_object("/clone/misc/cloth")->wear();  

} 

void init()

{

        object ob;

         ::init();

 if (interactive(ob = this_player()) && !is_fighting() ) {

                remove_call_out("greeting");

                call_out("greeting", 1, ob);

        }

}



void greeting(object me)

{

       command("look " + me->query("id"));

        if(present("shi kuai", this_player()) ) 

       {command("say 这位施主您辛苦了，快把身上的石头放下来吧！"); }        if(!present("shi kuai", this_player()) ) {

       command("say 这位施主光临宝庵，不知有何贵干？我们这座“温柔庵”还未修建完毕，还请施主多多包涵！"); }       }





