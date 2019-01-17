// gaibang npc code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void halt();
void create()
{
        set_name("�����", ({"yu hongxing", "yu", "hongxing"}));
        set("title","ؤ��˴�����");
        set("gender", "����");
        set("age", 30);
        set("long",
                "����λЦ���е�ؤ��˴����ӣ����Զ��ǣ����С���á�\n");
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

        create_family("ؤ��", 19, "����");
        setup();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="ؤ��")
        {
		command("say ����ؤ����Ҫһ��һ������"+ RANK_D->query_respect(ob)+ "��Ҫ��һ����������");
                return;
        }
        if (ob->query("dai")<7)
        {
               	command("say " + RANK_D->query_respect(ob) + "�Ĵ������������ܰ��ұ���");
                return;
        }
/*
        if ((int)ob->query("score")<700){
            command("say �ҿɲ��ղ����ڱ���֮��.");
            return;
         }
*/
        if (ob->query("dai")== 7 )
        {
        	if( ob->query("int") < 25 ) return;
	        command("say �����������Ϊ����ֻ���߹������˼Һ��Ҳ��ر���Щ����ͽ����");
        	command("say ��Ҷ�ҪΪ��Զ���밡��");
                command("recruit " + ob->query("id"));
                this_player()->set("title","ؤ���ߴ�����");
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α�������С�л��أ�");
        return;
}

int accept_object(object ob, object obj)
{
        object me = this_object();

        int n;
        n=ob->query("dai");

        if((obj->query("id") == "qingzhu ling")
        && ((string)ob->query("family/family_name")== "ؤ��"))
        {
            if ((int)ob->query("score")<n*100)
             {
               command("say "+RANK_D->query_respect(ob)+"С�ֵܶԱ��ŵ����ĺ���Ƿȱ��һ��");
               return 0;
             }
            if (ob->query("combat_exp")<(2000+500*(n-1))*n*n)
             {
               command("say "+RANK_D->query_respect(ob)+"���鲻������������������");
               return 0;
             }
            if (ob->query("dai")==8)
             {
                ob->set_temp("fight_ok_8",1);
                command("say �ã���Ȼ�ѵõ�������ɣ����Ǿ�����֤һ���书��");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
            }
            else
            {
                command("say "+ RANK_D->query_respect(ob) +"��λ���ԣ����ǲ��ܱȻ���");
                return 0;
            }
        }
        command("smile");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
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
		command("say ������û�գ�" + RANK_D->query_respect(ob) + "���ԵȻ���ٱȡ�");
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
                command("say ����" + RANK_D->query_respect(ob) +
                        "���ö����ϰ�������ڱ����������г���ͷ�� !\n");
                return 1;
        }

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
                command("say ������ʤ�����������ؤ��ļѵ��� ! ��ϲ���� !\n");
                message_vision("$N����$nһ�������\n", me, ob);
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
