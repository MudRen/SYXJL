
#include <ansi.h>



inherit NPC;

inherit F_MASTER;



void consider();



void create()

{

        set_name("洪七公", ({"hong qigong", "hong", "qigong"}));

        set("nickname", GRN "九指神丐" NOR);

        set("title",MAG "丐帮" NOR + YEL "第十七代" NOR+ MAG "掌门" NOR);

        set("gender", "男性");

        set("age", 75);

        set("long", 

                "他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");

        set("attitude", "peaceful");

        

        set("str", 30);

        set("int", 24);

        set("con", 30);

        set("dex", 24);



        set("chat_chance", 1);

        set("chat_msg", ({

                "洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",

                "洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",

                "洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",

//              (: random_move :),

        }));

      set("inquiry", ([
              "青竹林" : "东北西北东西北。\n",
              "丐帮" : "东北西北东西北。\n",
              "名菜" : "我看呀，这天下的名菜都比不上蓉儿做的叫化鸡和玉笛谁家听落。\n",
              "拜师" : "你可以去东城门的我帮总舵拜鲁有脚。\n",
      ]));


        set("qi", 4000);

        set("max_qi", 4000);

        set("jing", 1000);

        set("max_jing", 1000);

        set("neili", 4000);

        set("max_neili", 4000);

        set("jiali", 150);

        

        set("combat_exp",2000000);

        set("score", 200000);

         

         set("chat_chance_combat", 100);

        set("chat_msg_combat", ({

                (: consider :),

                (: perform_action, "staff.chan" :),

                (: exert_function , "powerup" :)

        }) );

        set_skill("force", 300);             // 基本内功

        set_skill("huntian-qigong", 300);    // 混天气功

        set_skill("strike", 300);

        set_skill("xianglong-zhang", 300);   // 降龙十八掌

        set_skill("dodge", 300);             // 基本躲闪

        set_skill("xiaoyaoyou", 300);        // 逍遥游

        set_skill("parry", 300);             // 基本招架

        set_skill("staff", 300);             // 基本棍杖

        set_skill("dagou-bang", 300);        // 打狗棒法

        set_skill("begging", 300);           // 叫化绝活

        set_skill("checking", 300);          // 道听途说

        

        map_skill("force", "huntian-qigong");

        map_skill("strike", "xianglong-zhang");

        map_skill("dodge", "xiaoyaoyou");

        map_skill("parry", "dagou-bang");

        map_skill("staff", "dagou-bang");



        prepare_skill("strike", "xianglong-zhang");

        

        create_family("丐帮", 17, "帮主");

        setup();

        

        carry_object(__DIR__"yuzhu_zhang");

        carry_object(__DIR__"jiaohuaji");

}



void attempt_apprentice(object ob)

{

        if ((string)ob->query("family/family_name")!="丐帮")

        {

                command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob)+ "先要从一袋弟子做起。");

                return;

        }

        if ((int)ob->query("score")<1000){

            command("shake"+ob->query("id"));

            command("say 小兄弟如能为本帮立下点功劳,我一定收你.");

            return;

             }         

        if (ob->query("dai")<9)

        {

                command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");

                return;

        }

        if (ob->query("dai")== 9 )

        {

        if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {

                command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");

                return;

        }

//      if ((string)ob->query("family/family_name") != "" &&

//          (string)ob->query("family/family_name") != "丐帮") {

//              command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老叫化呢？");

//              return;

//      }

        //command("say " + RANK_D->query_respect(ob) + "各项条件都不错，只可惜老叫化现在没力气收徒……");

        command("recruit " + ob->query("id"));

        this_player()->set("title",MAG "丐帮" NOR + YEL +"九袋" NOR + MAG "长老" NOR);

}



}



int accept_object(object who, object ob)

{



        object me=this_player();

        mapping myfam;

        if (ob->query("food_supply") <= 0)

                return 0;

        if ((string)ob->query("name") != "叫化鸡") {

                command("say 老叫化对" + (string)ob->query("name") + "没什么兴趣……");

                return 0;

        }

        if (query("food") >= max_food_capacity() - ob->query("food_supply")) {

                command("say 老叫化现在饱得很。");

                return 0;

        }

        command("say 啊……这正是我想吃的叫化鸡呀！");

        command("eat ji");

        if (!(myfam = this_player()->query("family")) || myfam["family_name"] == "丐帮" )

        {       

                command("say 既然你如此孝顺，我就教你这招「雷霆降龙」。");

                if (me->query_skill("xianglong-zhang", 1) >=135)

                {

                        say("你听了洪七公的讲解，学会了这一招。\n");

                        me->set("leiting",1);

                        return 1;

                }

                else

                {

                        say("由于你的降龙十八掌等级不够，对洪七公的讲解没有听懂。\n");

                        return 1;

                }

        }

        else

        {       command("say 我可没法报答你呀");

                return 1;

        }

        return 1;

}

void consider()

{

        int i, flag = 0;

        object *enemy;



        enemy = query_enemy() - ({ 0 });

        for(i=0; i<sizeof(enemy); i++) {

                if( !living(enemy[i]) ) continue;

                if( enemy[i]->query_temp("weapon") ) {

                        flag++;

                        if(     !query_temp("weapon") ) {

                                say(RED "\n洪七公说道：“既然" + RANK_D->query_respect(enemy[i]) + "使用兵刃，老叫化空手接招未免不敬！”\n\n" NOR);

                                command("wield yuzhu zhang");

                                break;

                        }

                }

        }

        if( !flag && query_temp("weapon") ) {

                if( sizeof(enemy) > 1 )

                        say(RED "\n洪七公说道：“嗯... 既然" + chinese_number(sizeof(enemy)) + "位都是空手，老叫化理当奉陪！”\n\n" NOR);

                else

                        say(RED "\n洪七公说道：“既然" + RANK_D->query_respect(enemy[0]) + "不使兵刃，老叫化自然奉陪！”\n\n" NOR);

                command("unwield yuzhu zhang");

        }

}

