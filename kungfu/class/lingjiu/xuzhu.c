// /NPC xuzhu.c
// /NPC xuzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("虚竹", ({ "xu zhu", "xu", "zhu" }));
        set("long",
            "这是一个二十五六岁的年轻人, 浓眉大眼,\n"+
            "大大的鼻子扁平下塌, 容貌颇为丑陋. \n"+
            "身穿一件华贵雅致的长袍, 倒使他更显几分精神.\n"+
            "他就是天山童姥的救命恩人.\n");
        set("title", "灵鹫宫掌门人");
        set("gender", "男性");
        set("age", 26);
        set("nickname", HIR "梦郎" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 25);
        set("con", 40);
        set("dex", 40);
        set("per", 20);

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);

        set("combat_exp", 1500000);
        set("score", 20000);
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("hand",200);
        set_skill("literate",200);
        set_skill("strike", 200);

        set_skill("zhemei-shou",200);
        set_skill("liuyang-zhang",200);
        set_skill("yueying-wubu",200);
        set_skill("bahuang-gong", 200);
        set_skill("sword", 200);
        set_skill("tianyu-qijian", 200);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "tianyu-qijian");
        map_skill("sword", "tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");
        create_family("灵鹫宫",2, "弟子");
        set("no_get",1);
        setup();
        carry_object("/d/lingjiu/obj/changpao")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("silver",50);
}



void init()
{
       object ob;

       ::init();

        ob = this_player();
        if((int)ob->query("score") < -1 &&ob->query("family/master_id")=="xu zhu")
        {
                    command("chat "+ob->query("name")+"！你为人不忠不义，我岂能仍是你的师傅。\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","灵鹫宫" + RED + "弃徒" NOR);
        }

}

void attempt_apprentice(object ob)
{
   if ((int)ob->query_skill("bahuang-gong", 1) < 50)
           {
                command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
                return;
           }
    if ((int)ob->query("score") < 200 ) {
        command("say 你对本门的贡献还不够,还得努力呀!");
                return;
     }

   if ((string)ob->query("gender")=="女性")
   {
                message_vision("虚竹垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
       command("recruit " + ob->query("id"));
                if((string)ob->query("class") != "dancer")
                        ob->set("class", "dancer");
       return;}
   else
      {
                message_vision("虚竹瞪着你看了半天,说道：“阁下不会是想来抢我的生意吧?”\n",ob);
       return;}
}



void do_kill(string arg)
{
        object me = this_player();
        object obj;

        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "xu zhu" || arg == "xu")
                obj->kill_ob(me);
        else obj->fight_ob(me);

        me->fight_ob(obj);
}


int accept_fight(object ob)
{
        object me  = this_object();

        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        if ( me->is_fighting()) return 0;

        if ( !present(ob, environment()) ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);

        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        if ( !present(ob, environment()) ) return 1;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if( me->is_fighting() )
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {

                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }

        return 1;
}


