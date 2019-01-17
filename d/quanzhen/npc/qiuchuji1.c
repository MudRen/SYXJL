//qiuchuji.c  �𴦻�
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("�𴦻�", ({"master qiu","qiu chuji", "qiu", "chuji"}));
        set("nickname", HIC"������"NOR);
        set("gender", "����");
        set("age", 50);
        set("long",
             "���������ᣬ��ɷ��˫Ŀ��������\n"
             "�������������ϱ����������ĳ����ӡ�\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 35);
        set("int", 31);
        set("con", 35);
        set("dex", 31);
        set("per", 25);

        set("chat_chance", 1);
        set("chat_msg", ({
                "�𴦻�˵������û�̵ܽ��������Բ������ĸ��ס���\n",
                "�𴦻�̾�˿�������������ӽ��˻�����Ĺ�����������󾸶���������\n",
             "�𴦻��૵������������澭���ǵ�����ѻ��˼�ʮ����Ѫд�ɵ������书�ܼ���
                             ���������޵� ���� \n",
//              (: random_move :),
        }));
        set("inquiry", ([
                "������Ĺ":"��������������ǻ�����Ĺ��ȫ��̵��Ӳ������ڣ�Υ�����ʦ�š�\n",
      "С��Ů":"������Ĺ�������ˣ��书��ɲ⡣\n",
        ]));

        set("qi", 1800);
        set("max_qi", 1800);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        
        set("combat_exp", 2500000);
        set("score", 200000);
         
        set_skill("force", 200);                 // �����ڹ�
           set_skill("tiangang-zhengqi", 200);//�������
        set_skill("unarmed", 200);             // ����ȭ��
         set_skill("kongming-quan", 200);       //����ȭ 
         set_skill("dodge", 200);             // ��������
           set_skill("qixing-huanwei", 200);//���ǻ�λ
          set_skill("parry", 200);             // �����м�
        set_skill("sword", 200);             // ��������
         set_skill("quanzhen-jianfa", 220);//����� 
        set_skill("taoism", 200);            //��ѧ�ķ�  
        set_skill("literate",200);           //����д��
        set_skill("qixing-array",220); 
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
      map_skill("parry", "quanzhen-jianfa");
      map_skill("sword", "quanzhen-jianfa");
        
                    set("no_get", 1);
        
        create_family("ȫ���", 2, "���ƽ�");
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );

        
        setup();
        
        carry_object("/d/quanzhen/npc/obj/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/greyrobe")->wear();

}
/*
void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="master qiu")
       {
         command("chat "+ob->query("name")+"! ��ɱ��Խ��������Ϊ���ҽ��������㣬�ӽ��Ժ������Ϊ֪�ɡ�����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title",RED"ȫ���" + RED + "��ͽ" NOR); 
       }
}               
*/
void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping ob_fam  = ob->query("family");
        mapping my_fam  = me->query("family");

        
        if ( ob_fam["generation"] <= my_fam["generation"] )
        {
                command("say " + RANK_D->query_respect(ob) + "��ƶ������ҵ� !");
                return;
        }
        
        if ((int)ob->query_str() < 30 || (int)ob->query_con() < 30) {
                command("say ����ʿ��Ҫ�ܳԿ����ͣ������徲���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ���ʿ��");
                return;
        }
        if ((string)ob->query("family/family_name") != "" &&
            (string)ob->query("family/family_name") != "ȫ���") {
                command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������ݱ������أ�");
                return;
        }
       if ((int)ob->query_skill("tiangang-zhengqi", 1) < 80) {
                command("say ��ȫ������ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ������������϶��µ㹦��");
                return;
       }
       if ((int)ob->query_skill("quanzhen-jianfa", 1) < 100) {
                command("say ��ȫ��̽����������£�������˫��"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ����ȫ�潣���϶��µ㹦��");
                return;
       }
       command("smile");  
       command("say �ðɣ�ƶ�����������ˡ�");
       command("recruit " + ob->query("id")); 
       ob->set("title","ȫ��̳������˰�ͽ");   
       ob->set("class","sworder");       
        
}
/*
void init()
{
        mapping mine;
        object me, room;

        me = this_player();

        if (!mapp(mine = me->query("family"))) 
                return;

        if(!( room = find_object("/d/quzanzhen/cangjingge1")) )
        room = load_object("/d/quanzhen/cangjingge1");
              if (me->query("family/master_id")=="master qiu")
                  command("say ��ͽ���������ˣ�\n");             

        if( (mapp(mine = me->query("family")) && mine["family_name"] != "ȫ���")
 || (present("master qiu", room) && (!present("letter", me))&&me->query("family/master_id")!="master qiu")  )
        {
                  command("say �󵨿�ͽ������ɱ�˴���ؾ��󣬿���!\n");
                  call_out("kill_ob", 0, this_player()); 

                  COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));                
                  return;
        }
        return;
}
*/
