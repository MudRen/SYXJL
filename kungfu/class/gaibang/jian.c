#include <ansi.h>



inherit NPC;

inherit F_MASTER;



void consider();

int ask_me_1();

int ask_me_2();

int ask_me_3();



void create()

{

        set_name("����", ({"jian zhanglao", "jian", "zhanglao"}));

        set("title", "ؤ��Ŵ�����");

        set("nickname", GRN "ִ������" NOR);

        set("title",MAG "ؤ��" NOR + YEL "�Ŵ�" NOR+ MAG "����" NOR);

        set("gender", "����");

        set("age", 50);

        set("long",

                "������ؤ���ִ�����ϣ�������ִ�Ʒ����Լ�������ȡ�\n"

                "������������𣬵�������˭���������־������顣\n");



        set("attitude", "peaceful");



        set("str", 24);

        set("int", 20);

        set("con", 24);

        set("dex", 20);



        set("qi", 2000);

        set("max_qi", 2000);

        set("jing", 1000);

        set("max_jing", 100);

        set("neili", 1500);

        set("max_neili", 1500);

        set("jiali", 120);



        set("combat_exp", 1200000);

        set("score", 20000);



        set_skill("force", 125); // �����ڹ�

        set_skill("huntian-qigong", 120); // ��������

        set_skill("strike", 120); // �����Ʒ�

        set_skill("xianglong-zhang", 115); // ����ʮ����

        set_skill("dodge", 120); // ��������

        set_skill("xiaoyaoyou", 125); // ��ң��

        set_skill("parry", 115); // �����м�

        set_skill("staff", 120); // ��������



        map_skill("force", "huntian-qigong");

        map_skill("strike", "xianglong-zhang");

        map_skill("dodge", "xiaoyaoyou");



        prepare_skill("strike", "xianglong-zhang");



        create_family("ؤ��", 18, "�Ŵ�����");



        set("inquiry", ([

                "������":     (: ask_me_1 :),

                "����"  :     (: ask_me_2 :),

                "����"  :     (: ask_me_2 :),

		"����" :   (: ask_me_3 :),

                "����"  :     (: ask_me_2 :)

        ]));

 

        setup();

}



void init()
{

        object ob;

        mapping myfam;



        ::init();

        if (interactive(ob = this_player()) && !is_fighting()) {

                myfam = (mapping)ob->query("family");

                if ((!myfam || myfam["family_name"] != "ؤ��") &&

                        (!wizardp(ob))) {

                        remove_call_out("saying");

                        call_out("saying",2,ob);

                }

        }

}



void saying(object ob)

{

        if (!ob || environment(ob) != environment() || environment(ob)->query("short") !="ؤ�ﰵ��")
                return;

        message_vision("\n���Ͽ���$Nһ�ۣ������˵����������������˼�˵�Ҳ���"

            "�������ؤ����ӣ�\n���ֲ�����ؤ��Ҵ����ܿ��԰ɣ���\n"

            "˵������һ̧��$N˳��Ӧ��һ������ɵġ�ƨ�����ƽɳ����ʽ��"

            "������ߴ\n\n", ob);

        remove_call_out("kicking");

        call_out("kicking",1,ob);



}



void kicking(object ob)

{

        if (!ob || environment(ob) != environment())

                return;



        ob->move("/d/city/pomiao");

         message("vision","ֻ�����ء���һ����������" +  ob->query("name") +

                "��С������˳�����ƨ������һ�������Ьӡ��\n", environment(ob), ob);

}



void attempt_apprentice(object ob)

{

        command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�");

}



int ask_me_1()

{

        object obj;
        object ob=this_player();
	int n=ob->query("dai");

	if ((string)ob->query("family/family_name")!="ؤ��")

	{

		command("say "+ RANK_D->query_respect(ob) +"���Ұ����ˣ���ο��������");

		return 1;

	}

        if ((int)ob->query("score")<n*100){

           command("say С�ֵܻ��ǻ�ȥ��!��Ա��ﹱ�ײ���,������������.");

           return 1;

            }  	

          if (ob->query("combat_exp")<(2000+500*(n-1))*n*n)

	{

		command("say "+ RANK_D->query_respect(ob) +"���鲻���������������");

		return 1;

	}

	command("say �ðɣ�ƾ��������Ժ���Ĵ�ʦ���д����ա�");

        obj = new("d/gaibang/obj/qingzhu-ling1");

        obj->move(this_player());

	return 1;

}



int ask_me_2()

{

        object ob=this_player();

        if ((string)ob->query("family/family_name")!="ؤ��")

        {

                command("say "+ RANK_D->query_respect(ob) +"���Ұ����ˣ��˻��Ӻ�˵��");

                return 1;

        }

	command("say ����"+ RANK_D->query_respect(ob) +"�����ʦ�ֱ����ʤ���õ�������Ϳ���������");

	return 1;

}



int accept_object(object ob, object obj)

{

        object me = this_object();



	object obje;





        if((obj->query("id") == "qingzhu ling")

	&& ((string)ob->query("family/family_name")== "ؤ��")

	&& ob->query_temp("have_win"))

        {	

		command("say ��Ȼ"+ RANK_D->query_respect(ob) +"սʤ�˴�ʦ�֣��ǾͿ��������ˡ�");

	ob->delete_temp("have_win");

        ob->set("combat_exp", ob->query("combat_exp") + 500 * ob->query("dai"));

                obje=new("/d/gaibang/obj/gaibang-bag");

		ob->set("dai", ob->query("dai") + 1);

                obje->move(ob);

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



int ask_me_3()

{

	int i;

	object ob;

	object obj= this_player();



        if ((string)obj->query("family/family_name")!="ؤ��")

        {

                command("say "+ RANK_D->query_respect(obj) +"���Ұ����ˣ��˻��Ӻ�̸��");

                return 1;

        }



	if(!present("budai", obj))

        {

		command("say ��С�����˰ɣ�");

		for(i=1; i<= obj->query("dai"); i++)

		{

			ob=new("/d/gaibang/obj/gaibang-bag");

		ob->move(obj);

		}

        }

	else

		command("say ��Ĳ���û��ѽ��");



	return 1;

}

