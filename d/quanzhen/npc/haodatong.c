//haodatong.c  �´�ͨ
#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("�´�ͨ", ({"hao datong", "hao", "datong"}));
        set("nickname", HIC"������"NOR);
        set("gender", "����");
        set("age", 55);
        set("long",
             "���׷���ü�����׼��������Ż�ɫ���ۣ���ģ����ȫ��̵ĸ��֡�\n"
             "�����������������ߴ����֮һ�������ӡ��´�ͨ��\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("chat_chance", 1);
        set("chat_msg", ({
                "�´�ͨ˵�������Ǳ��̵��Ӳ�Ҫ���ߡ���\n",
//       (: random_move :),
        }));

        set("qi", 1800);
        set("max_qi", 1800);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 1700);
        set("max_neili", 1700);
        set("jiali", 110);
        
        set("combat_exp", 1800000);
        set("score", 50000);
 
        set_skill("force", 180);             // �����ڹ�
        set_skill("tiangang-zhengqi", 180);    //�������
        set_skill("unarmed", 180);           // ����ȭ��
        set_skill("kongming-quan", 180);    //����ȭ 
        set_skill("dodge",180);              // ��������
        set_skill("qixing-huanwei", 180);        //���ǻ�λ
        set_skill("parry", 180);             // �����м�
        set_skill("sword", 180);             // ��������
        set_skill("quanzhen-jianfa", 180);        //����� 
        set_skill("taoism", 180);            //��ѧ�ķ�  
        set_skill("literate",180);           //����д��
        set_skill("qixing-array", 200);  
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���",2,"����");
        
       set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );
                                
        setup();
     
       carry_object("/d/quanzhen/npc/obj/changjian")->wield();
       carry_object("/d/quanzhen/npc/obj/greyrobe")->wear();

}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="hao datong")
       {
         command("chat "+ob->query("name")+"! ��ɱ��Խ��������Ϊ���ҽ��������㣬�ӽ��Ժ������Ϊ֪�ɡ�����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","ȫ���" + RED + "��ͽ" NOR);        }
}               

void attempt_apprentice(object ob)
{
     mapping fam = ob->query("family");
      if (!fam || fam["family_name"] != "ȫ���"){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }       
      if((int)ob->query_skill("tiangang-zhengqi", 1) < 80) {
                command("say ��ȫ����书�ڹ��ǻ�����"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                return;
                }  
      if((int)ob->query_skill("sword", 1) < 80) {
                command("say �㽣����ô��ҽ̵��㲻һ��ѧ�ûᡣ"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                return;
                }
      if(ob->query_int() < 23) {
                command("say �ҵ��书��Ҫ�̸ߵ����Բ���ѧ�ᡣ");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say ��λ"+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
                }
      if(ob->query("gender") != "����") {
                command("say �ҿ�ֻ����ͽ����ȥ���徲ɢ�����԰ɡ�");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("recruit " + ob->query("id"));
        ob->set("title","ȫ��̹������˰�ͽ");
        ob->set("class","sworder");

}

void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "hao datong" || arg == "hao")
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

