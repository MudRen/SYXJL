// /NPC tonglao.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("天山童姥", ({ "tong lao", "tong", "lao" }));
        set("long",
            "她就是「灵鹫宫」的开山祖师.\n"+
            "乍一看似乎是个十七八岁的女子,可神情却是老气横秋.\n"+
            "双目如电,炯炯有神,向你瞧来时,自有一股凌人的威严.\n");
        set("title", "灵鹫宫主人");
        set("gender", "女性");
        set("age", 96);
        set("nickname", HIR "唯我独尊" NOR);
        set("shen_type",0);
        set("attitude", "peaceful");

        set("str", 25);
        set("int", 35);
        set("con", 40);
        set("dex", 40);

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);

        set("combat_exp", 3500000);
        set("score", 200000);
        set_skill("force", 300);
        set_skill("hantian-chuixue-jian", 300);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("hand",300);
        set_skill("strike", 300);
        set_skill("sword",300);
        set_skill("zhemei-shou",300);
        set_skill("liuyang-zhang",300);
        set_skill("tianyu-qijian",300);
        set_skill("yueying-wubu",300);
        set_skill("bahuang-gong", 300);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword","hantian-chuixue-jian");

        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");
create_family("灵鹫宫",1, "开山祖师");
       setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}

void init()
{
       object ob;
       ::init();

        ob = this_player();
        if((int)ob->query("score") < -1 &&ob->query("family/master_id")=="tong lao")
        {
                    command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","灵鹫宫" + RED + "弃徒" NOR);   
        }

}

void attempt_apprentice(object ob)
{

   if ((string)ob->query("gender")!="女性")
           {
                command("say 你找死啊!");
                return;
           }
   if ((int)ob->query_skill("bahuang-gong", 1) < 170) 
           {
                command("say " + RANK_D->query_respect(ob) + 

"是否还应该多练练八荒六合唯我独尊功？");
                return;
           }
    if ((int)ob->query("score") < 500 ) {
        command("say 你对本门的贡献还不够,还得努力呀!");
                return;
     }           
   if (ob->query_con() < 45) 
           {
                command("say 本门功法极为难练,你的根骨似乎不够.");
                return;
           }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "dancer")
     ob->set("class", "dancer");
   return;
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

