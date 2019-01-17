//sunbuer.c �ﲻ��

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("�ﲻ��", ({"sun buer", "sun", "buer"}));
        set("nickname", HIB"�徲ɢ��"NOR);
        set("gender", "Ů��");
        set("age", 39);
        set("long",
             "����Ŀ�ݣ���ɫ���壬�䴩һ����ɫ���ۣ�Ҳ�ڸǲ���������ɫ��\n"
             "������ȫ��������Ψһ��Ů�ԡ��徲ɢ�ˡ��ﲻ����\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 29);
        set("int", 32);
        set("con", 30);
        set("dex", 32); 
        set("per", 25);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ﲻ��˵�������Ǳ��̵��Ӳ�Ҫ���ߡ���\n",
//        (: random_move :),
        }));

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 1250);
        set("max_jing", 1250);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
        
        set("combat_exp", 1800000);
        set("score", 50000);
 
        set_skill("force", 180);             // �����ڹ�
        set_skill("tiangang-zhengqi", 180);    //�������
        set_skill("unarmed", 180);           // ����ȭ��
        set_skill("kongming-quan", 140);    //����ȭ 
        set_skill("dodge",180);              // ��������
        set_skill("qixing-huanwei", 180);        //���ǻ�λ
        set_skill("parry", 180);             // �����м�
        set_skill("sword", 180);             // ��������
        set_skill("quanzhen-jianfa", 180);        //����� 
        set_skill("taoism", 180);            //��ѧ�ķ�  
       set_skill("literate",180);           //����д��
        set_skill("qixing-array",200); 
  
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
     
       carry_object("/d/quanzhen/obj/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();

}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="sun buer")
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
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�������á�");
                command("say ��λ"+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
                }
      if(ob->query("gender") != "Ů��") {
                command("say �ҿ�ֻ��Ůͽ����ȥ����ʦ�������԰ɡ�");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("recruit " + ob->query("id"));
        ob->set("title","ȫ����徲ɢ�˰�ͽ");
        ob->set("class","sworder");
}
