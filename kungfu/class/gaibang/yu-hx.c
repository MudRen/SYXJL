// gaibang npc code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void halt();
void create()
{
        set_name("余洪兴", ({"yu hongxing", "yu", "hongxing"}));
        set("title","丐帮八袋弟子");
        set("gender", "男性");
        set("age", 30);
        set("long",
                "这是位笑眯眯的丐帮八袋弟子，生性多智，外号小吴用。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 30);
        set("con", 22);
        set("dex", 20);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: halt :),
        }));

        set("max_qi", 1520);
        set("max_jing", 330);
        set("neili", 1280);
        set("max_neili", 1280);
        set("jiali", 112);

        set("combat_exp", 820000);

        set_skill("force", 118);
        set_skill("huntian-qigong", 116);
        set_skill("strike", 118);
        set_skill("xianglong-zhang", 110);
        set_skill("dodge", 110);
        set_skill("xiaoyaoyou", 112);
        set_skill("parry", 111);
        set_skill("begging", 110);
        set_skill("stealing", 120);
        set_skill("checking", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 19, "弟子");
        setup();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="丐帮")
        {
		command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob)+ "先要从一袋弟子做起。");
                return;
        }
        if (ob->query("dai")<7)
        {
               	command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
/*
        if ((int)ob->query("score")<700){
            command("say 我可不收不忠于本帮之人.");
            return;
         }
*/
        if (ob->query("dai")== 7 )
        {
        	if( ob->query("int") < 25 ) return;
	        command("say 唉，本帮诚信为本，只有七公他老人家和我才特别收些聪明徒儿，");
        	command("say 大家都要为长远着想啊！");
                command("recruit " + ob->query("id"));
                this_player()->set("title","丐帮七袋弟子");
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}

int accept_object(object ob, object obj)
{
        object me = this_object();

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
            if (ob->query("dai")==8)
             {
                ob->set_temp("fight_ok_8",1);
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

        if ( !ob->query_temp("fight_ok_8") ) return 0;
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

          ob->delete_temp("fight_ok_8");
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
