// gaibang npc code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void halt();
void create()
{
        set_name("�����", ({"qiu wanjia", "qiu", "wanjia"}));
        set("title","ؤ���������");
        set("gender", "����");
        set("age", 27);
        set("long",
                "����λ������������ͷ�����ؤ��������ӡ�\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: halt :),
        }));

        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 50);

        set("combat_exp", 10000);

        set_skill("force", 45);
        set_skill("huntian-qigong", 45);
	set_skill("blade", 45);
	set_skill("liuhe-dao", 45);
        set_skill("hand", 45);
        set_skill("shexing-shou", 45);
        set_skill("dodge", 50);
        set_skill("xiaoyaoyou", 45);
        set_skill("parry", 43);
        set_skill("begging", 50);
        set_skill("stealing", 40);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
	map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("hand", "shexing-shou");

        create_family("ؤ��", 25, "����");
        setup();
}

void attempt_apprentice(object ob)
{
//        mapping fam;
	object obj;
if( ob->query("combat_exp") < 5500 && !(ob->query("is_beggar") && ob->query("family/family_name")!="ؤ��"))
        {
                command("say �ã���Ȼ" + RANK_D->query_respect(ob) + "Ը�����Ϊʦ���Ҿ��������ˡ�");
                ob->set("dai", 1);
		ob->set("is_beggar", 1);
		if (ob->query("class")!="bonze")
           	ob->set("class", "beggar");
                command("recruit " + ob->query("id"));
		if(!present("budai", this_player()))
		{
          	      obj=new("/d/gaibang/obj/gaibang-bag");
          	      obj->move(ob);
		}
                this_player()->set("title","ؤ��һ������");
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α�������С�л��أ�");
        return;


}

int accept_object(object ob, object obj)
{
        object me = this_object();
//        mapping my_fam  = me->query("family");
//        mapping ob_fam  = ob->query("family");
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
            if (ob->query("dai")==2)
   	     {
                ob->set_temp("fight_ok_2",1);
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

        if ( !ob->query_temp("fight_ok_2") ) return 0;
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

        ob->delete_temp("fight_ok_2");
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
