///ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
                   +"由于习练「九阴真经」走火入魔，已变得精\n"
                   +"神错乱，整日披头散发。\n");
        set("title", "老毒物");
        set("gender", "男性");
        set("age", 53);
        set("nickname", HIR "西毒" NOR);
        set("shen_type",-1);
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 29);
        set("con", 30);
        set("dex", 28);

        set("qi", 2500);
        set("max_qi", 2500);
        set("jing", 900);
        set("max_jing", 900);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);

        set("combat_exp", 1500000);
        set("score", 200000);

        set_skill("force", 300);
        set_skill("training", 300);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("hand",300);
        set_skill("finger",300);        
        set_skill("poison",300);        
        set_skill("staff", 300);
        set_skill("hamagong", 300);
        set_skill("chanchu-bufa", 300);
        set_skill("shedu-qiqiao",300);        
        set_skill("shexing-diaoshou", 300);
        set_skill("lingshe-zhangfa", 300);

        map_skill("force", "hamagong");
        map_skill("dodge", "chanchu-bufa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("hand", "shexing-diaoshou");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("staff", "lingshe-zhangfa");
         map_skill("poison", "shedu-qiqiao");        

        create_family("白驼山派",1, "开山祖师");
        set("chat_chance",2);
        set("chat_msg",({
         "欧阳锋自言自语道：何日白驼山派才能重霸江湖呢…\n",
         "欧阳锋道：我儿欧阳克必能够重振白驼山派雄风！\n",
         "欧阳锋道：江湖险恶，困难重重哪！\n",
        }));
            set("no_get",1);
        setup();
         carry_object("/d/baituo/obj/shezhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",50);
}

     void init()
{
        object ob;

        ::init();

        ob = this_player();
         if((int)ob->query("shen")>=0&&ob->query("family/master_id")=="ouyang feng")
        {
                    command("chat "+ob->query("name")+"!你心慈手软，怎能做我邪派弟子，给我滚蛋。\n");
                  command("expell "+ ob->query("id"));
                    this_player()->set("title","白驼山派" + RED + "弃徒" NOR);   
        }

}     

void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<100000)
        {
          message_vision("欧阳锋对$N笑道：你的经验太低了,我还不能收你！\n",ob);
        return ;
         }
   message_vision("欧阳锋拍拍$N的头，微微点了点头。\n",ob);
   command("recruit " + ob->query("id"));
   return;
}
