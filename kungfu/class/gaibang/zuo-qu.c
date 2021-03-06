// gaibang npc code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void halt();
void create()
{
        set_name("左全", ({"zuo quan", "zuo", "quan"}));
        set("title","丐帮七袋弟子");
        set("gender", "男性");
        set("age", 35);
        set("long",
                "这是位豪爽大方的丐帮七袋弟子，看来是个北地豪杰。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 26);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: halt :),
        }));

        set("max_qi", 1200);
        set("max_jing", 300);
        set("neili", 1010);
        set("max_neili", 1010);
        set("jiali", 106);

        set("combat_exp", 408000);

        set_skill("force", 103);
        set_skill("huntian-qigong", 100);
        set_skill("strike", 100);
        set_skill("xianglong-zhang", 103);
        set_skill("dodge", 100);
        set_skill("xiaoyaoyou", 101);
        set_skill("parry", 100);
        set_skill("begging", 80);
        set_skill("checking", 80);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 19, "弟子");
        setup();
}

void attempt_apprentice(object ob)
{
//        mapping fam;
        if ((string)ob->query("family/family_name")!="丐帮")
        {
		command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob)+ "先要从一袋弟子做起。");
                return;
        }
        if (ob->query("dai")<6)
        {
               	command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
/*
        if ((int)ob->query("score")<600){
          command("say 我虽然是个粗人,但也知效忠本帮,你这种不忠不义之人,我不会收你的.");
          return;
          }        
*/
        if (ob->query("dai")== 6 )
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你了。");
        	command("say 希望你能好好学习本门武功，将来为丐帮争一口气！。");
                command("recruit " + ob->query("id"));
                this_player()->set("title","丐帮六袋弟子");
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}

int accept_object(object ob, object obj)
{
        object me = this_object();

//      mapping my_fam  = me->query("family");
//        mapping ob_fam  = ob->query("family");
        int n;
        n=ob->query("dai");

        if((obj->query("id") == "qingzhu ling")
        && ((string)ob->query("family/family_name")== "丐帮"))
        {
            if ((int)ob->query("score")<n*100)
             {
               command("say "+RANK_D->query_respect(ob)+"小兄弟对本门的忠心好象还欠缺了一点");
               return 0;
             }
            if (ob->query("combat_exp")<(2000+500*(n-1))*n*n)
             {
               command("say "+RANK_D->query_respect(ob)+"经验不够，那里来的青竹令");
               return 0;
             }
            if (ob->query("dai")==7)
             {
                ob->set_temp("fight_ok_7",1);
                command("say 好，既然已得到简长老许可，我们就来验证一下武功。");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
            }
            else
            {
                command("say "+ RANK_D->query_respect(ob) +"袋位不对，我们不能比划。");
                return 0;
            }
        }
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

int accept_fight(object ob)
{
        object me  = this_object();

        if ( !ob->query_temp("fight_ok_7") ) return 0;
        if (me->is_fighting())
	{
		command("say 我正在没空，" + RANK_D->query_respect(ob) + "可以等会儿再比。");
		return 0;
	}
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        remove_call_out("checking");
        call_out("checking", 1, me, ob);

        ob->delete_temp("fight_ok_7");
        me->set("bihua",1);

        return 1;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (me->is_fighting())
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1;

        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
        {
                command("say 看来" + RANK_D->query_respect(ob) +
                        "还得多加练习，方能在本帮诸多弟子中出人头地 !\n");
                return 1;
        }

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
                command("say 青出於蓝胜於蓝，不愧是丐帮的佳弟子 ! 恭喜你了 !\n");
                message_vision("$N交给$n一个青竹令。\n", me, ob);
                ob->set_temp("have_win",1);
                obj=new("/d/gaibang/obj/qingzhu-ling2");
                obj->move(ob);
                return 1;
        }


        return 1;
}

void halt()
{
        this_object()->delete("bihua");
        return ;
}
