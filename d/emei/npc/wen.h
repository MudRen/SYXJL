// wen.h for fight and get letter from wen 



void init()

{

  object me = this_player();

  object ob = this_object();

  if( me->query("family/master_id") == ob->query("id") )

    if(me->query("score") < -100)

       {            

         command("shake");

         command("say ���������ʣ��㶼��ʦ�Ÿ���Щʲô���������������ʦ����\n");

         command("expell "+ me->query("id"));

       }

}





int accept_object(object ob, object obj)

{

        object me = this_object();

        mapping my_fam  = me->query("family");

        mapping ob_fam  = ob->query("family");

        if ( ob->query_temp("have_letter") && present("tuijian xin1", ob) )

        {

                command("say �������������ҵ��Ƽ���ȥ��ʦ���� ?");

                return 0;

        }

        if((obj->query("id") == "emei ling")

        && ob_fam["generation"] == my_fam["generation"] + 1

        && !ob->query_temp("have_letter") )

         {

                ob->set_temp("fight_ok",1);

                command("say �ã���Ȼ�ѵõ�������ɣ����Ǿ�����֤һ���书��");

                remove_call_out("destroying");

                call_out("destroying", 1, me, obj);

                return 1;

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

        if ( !ob->query_temp("fight_ok") ) return 0;



        set("eff_qi",me->query("max_qi"));

        set("qi",me->query("max_qi"));

        set("neili",me->query("max_neili"));

        set("jing",me->query("max_jing"));

        set("eff_jing",me->query("max_jing"));

        if((int)me->query_skill("sword",1))

            carry_object(__DIR__"obj/changjian")->wield();

        if((int)me->query_skill("blade",1))

            carry_object(__DIR__"obj/gangdao")->wield();



        remove_call_out("checking");

        call_out("checking", 1, me, ob);

        ob->delete_temp("fight_ok");

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

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )

        {

                command("say ������ʤ����������Ƕ����ɵļѵ��� ! ��ϲ���� !\n");

                message_vision("$N����$nһ���Ƽ��š�\n", me, ob);

                ob->set_temp("have_letter",1);

                obj=new(__DIR__"obj/xin1");

                obj->move(ob);

                return 1;

        }

        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )

        {

                command("say ����" + RANK_D->query_respect(ob) +

                        "���ö����ϰ�������ڶ����������г���ͷ�� !\n");

                return 1;

        }

        return 1;

}

void attempt_apprentice(object ob)

{

        object me  = this_object();

        mapping ob_fam;

        mapping my_fam  = me->query("family");

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")

        {

                command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");

                return;

        }  

        if( !(me->query("class")) && ob->query("class") == "bonze" )

        {

                command("say �Ҳ��ճ��ҵ��ӣ�ʩ����ذɡ�");

                return;

        }

        if ( ob_fam["generation"] == 0 )

        {

                command("say �����ӷ�ƶ������������ҵĵ����ˡ�");

                command("recruit " + ob->query("id"));

                return;

        } 

        if ( ob_fam["generation"] == (my_fam["generation"] + 1) )

        {

                command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");

                command("recruit " + ob->query("id"));

        }

        if ( ob_fam["generation"] <= my_fam["generation"] )

        {

                command("say " + RANK_D->query_respect(ob) + "��ƶ������ҵ� !");

                return;

        }

        return;

}

