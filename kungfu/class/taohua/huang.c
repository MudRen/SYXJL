#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("黄药师", ({"huang yaoshi", "huang", "yaoshi"}));
    set("nickname", HIY "东邪" NOR );
    set("gender", "男性");
    set("age", 42);
    set("long", 
        "他就是桃花岛主。行事好恶全由己心，因此被人称作「东邪」。\n");
    set("attitude", "peaceful");
        
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
        "黄药师叹了口气道：“唉 …… 蓉儿这苦命的孩子，从小就没了娘 ……”\n",
        "黄药师低头沉思，悠然不语。\n",
    }));
    set("inquiry", ([
        "黄蓉"     : "你敢直称我女儿的闺名？ \n",
        "九阴真经" : "如果你能帮我取得真经上册，我一定重重谢你。\n",
    ]));

    set("qi", 3000);
    set("max_qi", 3000);
    set("jing", 3000);
    set("max_jing", 3000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 100);
        
    set("combat_exp", 1500000);
    set("score", 0);
         
    set_skill("force", 300);             // 基本内功
    set_skill("bibo-shengong", 300);     // 碧波神功

//    set_skill("claw", 220);              // 基本爪法

    set_skill("finger", 300);            // 基本指法
      set_skill("tanzhi-shentong", 300);   // 弹指神通
    set_skill("unarmed", 300);           // 基本拳脚
    set_skill("luoying-zhang", 260);     // 落英神剑掌
    set_skill("hand", 230);              // 基本手法
    set_skill("cuixin-zhang", 260);      // 催心掌
    set_skill("xuanfeng-tui", 260);      // 旋风扫叶腿
    set_skill("lanhua-shou", 230);       // 兰花拂穴手
    set_skill("dodge", 300);             // 基本躲闪
  set_skill("anying-fuxiang", 300);    // 暗影浮香
    set_skill("parry", 300);             // 基本招架
    set_skill("strike", 260);            // 基本掌法
    set_skill("sword", 300);             // 基本剑法
    set_skill("luoying-shenjian", 300);  // 落英神剑
    set_skill("qimen-wuxing",250);       // 奇门五行
    set_skill("literate",400);           // 读书识字
        
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("strike", "cuixin-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "luoying-shenjian");
    map_skill("sword"  , "luoying-shenjian");
        
    create_family("桃花岛", 1, "岛主");
    setup();
        
    this_player()->carry_object(__DIR__"obj/yuxiao")->wield();
    this_player()->carry_object(__DIR__"obj/bupao")->wear();
    this_player()->carry_object(__DIR__"obj/jiuyin2");
    
}

void init()
{
       object ob;

       ::init();

       if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        ob = this_player();
        if((int)ob->query("score") < 0 &&ob->query("family/master_id")=="huang yaoshi")
        {
                    command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","桃花岛" + RED + "弃徒" NOR);   
        }

       }
}


void attempt_apprentice(object ob)
{
        string name,new_name; 
        if (ob->query_int() < 30) {
        command("say 我不收资质差的弟子，您请回吧！");
                return;
    }
    if ((int)ob->query_skill("bibo-shengong",1) < 50 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
                return;
}
    if ((int)ob->query("score") < 500 ) {
        command("say 你对本门的贡献还不够,还得努力呀!");
                return;
 
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say 我桃花岛与世隔绝，向来不与您这种成名人物打交道，您请回吧！");
                return;
        }
    command("say 很好，很好。");
    name = ob->query("name");
    new_name = name[0..3] + "风";
    ob->set("name", new_name);
    command("say 从今以后你名字叫做" + new_name + "!");    
    command("recruit " + ob->query("id"));
}

int recognize_apprentice(object ob)
{
        mapping myfam;
        if (mapp(ob->query("family"))) {
                myfam = (mapping)ob->query("family");
                if ( myfam["family_name"] == "桃花岛") return 1;
        }
        if ((int)ob->query_temp("tmark/黄") == 1 )
        message_vision("黄药师看了看$N，说道：咱们现在是谁也不欠谁,\n"
                          "你不要再找我学习技艺了。\n", ob);
        if (!(int)ob->query_temp("tmark/黄"))
                return 0; 
        ob->add_temp("tmark/黄", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        
        if ( (string) ob->query("id") =="jiuyin zhenjing1" ) {
                if (!(int)who->query_temp("tmark/黄")) who->set_temp("tmark/黄", 0);
                message_vision("黄药师看了看$N送来的秘籍，点了点头，说道：\n"
                               "难得你将真经送回。你送我的东西我就收下了。\n"
                               "作为补偿,你可以从我这里学点功夫。\n", who);
                who->add_temp("tmark/黄", 240);
                return 1;
        }
        return 0;
}





void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "huang yaoshi" || arg == "huang")
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

