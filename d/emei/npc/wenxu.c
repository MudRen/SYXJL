#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_join();
void create()
{
        set_name("文虚师太", ({
                "wenxu shitai",
                "wenxu",
                "shitai",
        }));
        set("long",
                "她是一位年轻的师太。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        set("class", "bonze");
        set("inquiry",([
                "剃度"  : (: ask_for_join :),
                "出家"  : (: ask_for_join :),
        ]));
        set("age", 28);
        set("shen_type", 1);
        set("str", 17);
        set("int", 20);
        set("con", 50);
        set("dex", 21);
        set("max_qi", 1000);

        set("max_jing", 500);

        set("neili", 1000);

        set("max_neili", 1000);

        set("jiali", 40);

        set("combat_exp", 60000);

        set("score", 100);

        set_skill("force", 60);

        set_skill("linji-zhuang", 60);

        set_skill("dodge", 70);

        set_skill("zhutian", 70);

        set_skill("jinding-mianzhang", 70);
        set_skill("strike", 70);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("fuliu-jian", 60);
       	set_skill("mahayana", 70);
        set_skill("literate", 60);
        map_skill("sword", "fuliu-jian");
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("parry", "jinding-mianzhang");
        prepare_skill("sword", "fuliu-jian");
        create_family("峨嵋派", 5, "弟子");
        setup();
          carry_object(__DIR__"obj/cloth")->wear();
          carry_object(__DIR__"obj/changjian")->wield();
}

void init()
{
        object me;
        me = this_player();
        if( me->query("family/master_id")=="wenxu shitai")
           if(me->query("shen")<=-100)
             {            
               command("shake");
               command("chat "+me->query("name")+"!你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
               command("expell "+ me->query("id"));
               this_player()->set("title","峨嵋派" + RED + "弃徒" NOR);   
             }

        add_action("do_kneel", "kneel");
}
string ask_for_join()
{
        object me;
        me = this_player();
        if( (string)me->query("class")=="bonze" )
                return "阿弥陀佛！你我同是出家人，何故跟贫尼开这等玩笑？\n";

        if(!undefinedp(me->query("marry/lover")))
                return "阿弥陀佛！施主尘缘未了，还是罢了吧。\n";
 
        if( (string)me->query("gender") != "女性" )
                return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，可去少林寺里受戒。\n";
        me->set_temp("pending/join_bonze", 1);
        return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}
int do_kneel()
{
        object me = this_player();
        string *prename =
         ({ "园", "悟", "法", "怡" });
        string name, new_name;
        if( !me->query_temp("pending/join_bonze") )
                return 0;
        message_vision(
                "$N双手合十，恭恭敬敬地跪了下来。\n\n"
                "$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n",
                me, this_object() );
        name = me->query("name");
        new_name = prename[random(sizeof(prename))] + name[0..1];
        command("say 从今以后你的法名叫做" + new_name + "。");
        command("smile");
        me->delete_temp("pending/join_bonze");
        me->set("name", new_name);
        me->set("class", "bonze");
        me->set("K_record", me->query("PKS") + me->query("MKS"));
        me->set("shen_record", me->query("shen"));
        me->set("shen", 0);
        return 1;
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "女性" )
        {
                command ("say 阿弥陀佛！施主呀，贫尼可不敢开这等玩笑啊。");
                return;
        }
        if( ob->query("shen") < 0)
           {
            command("say 阿弥陀佛！本派不收为非作歹之徒。");  
            command("sigh");
            command("say 以后多做善事吧！！阿弥陀佛！");                     
            return;
           }  
        if( (string)ob->query("class")!="bonze" )
        {  
                command("say 阿弥陀佛！贫尼就收下你做『俗家弟子』了。");
                command("say 以后想出家的话跟我说一声吧。阿弥陀佛！");              
        }
        command("say 阿弥陀佛，善哉！善哉！");
        ob->set("xiashan",1);
        command("recruit " + ob->query("id"));
}
