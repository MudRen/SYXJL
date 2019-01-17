
#include <ansi.h>



inherit NPC;

inherit F_MASTER;



void consider();



void create()

{

        set_name("���߹�", ({"hong qigong", "hong", "qigong"}));

        set("nickname", GRN "��ָ��ؤ" NOR);

        set("title",MAG "ؤ��" NOR + YEL "��ʮ�ߴ�" NOR+ MAG "����" NOR);

        set("gender", "����");

        set("age", 75);

        set("long", 

                "������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");

        set("attitude", "peaceful");

        

        set("str", 30);

        set("int", 24);

        set("con", 30);

        set("dex", 24);



        set("chat_chance", 1);

        set("chat_msg", ({

                "���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",

                "���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",

                "���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",

//              (: random_move :),

        }));

      set("inquiry", ([
              "������" : "����������������\n",
              "ؤ��" : "����������������\n",
              "����" : "�ҿ�ѽ�������µ����˶��Ȳ����ض����Ľл��������˭�����䡣\n",
              "��ʦ" : "�����ȥ�����ŵ��Ұ��ܶ��³�нš�\n",
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

        set_skill("force", 300);             // �����ڹ�

        set_skill("huntian-qigong", 300);    // ��������

        set_skill("strike", 300);

        set_skill("xianglong-zhang", 300);   // ����ʮ����

        set_skill("dodge", 300);             // ��������

        set_skill("xiaoyaoyou", 300);        // ��ң��

        set_skill("parry", 300);             // �����м�

        set_skill("staff", 300);             // ��������

        set_skill("dagou-bang", 300);        // �򹷰���

        set_skill("begging", 300);           // �л�����

        set_skill("checking", 300);          // ����;˵

        

        map_skill("force", "huntian-qigong");

        map_skill("strike", "xianglong-zhang");

        map_skill("dodge", "xiaoyaoyou");

        map_skill("parry", "dagou-bang");

        map_skill("staff", "dagou-bang");



        prepare_skill("strike", "xianglong-zhang");

        

        create_family("ؤ��", 17, "����");

        setup();

        

        carry_object(__DIR__"yuzhu_zhang");

        carry_object(__DIR__"jiaohuaji");

}



void attempt_apprentice(object ob)

{

        if ((string)ob->query("family/family_name")!="ؤ��")

        {

                command("say ����ؤ����Ҫһ��һ������"+ RANK_D->query_respect(ob)+ "��Ҫ��һ����������");

                return;

        }

        if ((int)ob->query("score")<1000){

            command("shake"+ob->query("id"));

            command("say С�ֵ�����Ϊ�������µ㹦��,��һ������.");

            return;

             }         

        if (ob->query("dai")<9)

        {

                command("say " + RANK_D->query_respect(ob) + "�Ĵ������������ܰ��ұ���");

                return;

        }

        if (ob->query("dai")== 9 )

        {

        if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {

                command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");

                return;

        }

//      if ((string)ob->query("family/family_name") != "" &&

//          (string)ob->query("family/family_name") != "ؤ��") {

//              command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");

//              return;

//      }

        //command("say " + RANK_D->query_respect(ob) + "��������������ֻ��ϧ�Ͻл�����û������ͽ����");

        command("recruit " + ob->query("id"));

        this_player()->set("title",MAG "ؤ��" NOR + YEL +"�Ŵ�" NOR + MAG "����" NOR);

}



}



int accept_object(object who, object ob)

{



        object me=this_player();

        mapping myfam;

        if (ob->query("food_supply") <= 0)

                return 0;

        if ((string)ob->query("name") != "�л���") {

                command("say �Ͻл���" + (string)ob->query("name") + "ûʲô��Ȥ����");

                return 0;

        }

        if (query("food") >= max_food_capacity() - ob->query("food_supply")) {

                command("say �Ͻл����ڱ��úܡ�");

                return 0;

        }

        command("say ����������������ԵĽл���ѽ��");

        command("eat ji");

        if (!(myfam = this_player()->query("family")) || myfam["family_name"] == "ؤ��" )

        {       

                command("say ��Ȼ�����Т˳���Ҿͽ������С�������������");

                if (me->query_skill("xianglong-zhang", 1) >=135)

                {

                        say("�����˺��߹��Ľ��⣬ѧ������һ�С�\n");

                        me->set("leiting",1);

                        return 1;

                }

                else

                {

                        say("������Ľ���ʮ���Ƶȼ��������Ժ��߹��Ľ���û��������\n");

                        return 1;

                }

        }

        else

        {       command("say �ҿ�û��������ѽ");

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

                                say(RED "\n���߹�˵��������Ȼ" + RANK_D->query_respect(enemy[i]) + "ʹ�ñ��У��Ͻл����ֽ���δ�ⲻ������\n\n" NOR);

                                command("wield yuzhu zhang");

                                break;

                        }

                }

        }

        if( !flag && query_temp("weapon") ) {

                if( sizeof(enemy) > 1 )

                        say(RED "\n���߹�˵��������... ��Ȼ" + chinese_number(sizeof(enemy)) + "λ���ǿ��֣��Ͻл������㣡��\n\n" NOR);

                else

                        say(RED "\n���߹�˵��������Ȼ" + RANK_D->query_respect(enemy[0]) + "��ʹ���У��Ͻл���Ȼ���㣡��\n\n" NOR);

                command("unwield yuzhu zhang");

        }

}

