// longwang.c ��ɼ����
// by tony  97/7
#include <ansi.h>
inherit NPC;

object ob = this_object();
void create()
{
        set_name("���˿",({"dai qisi","dai","longwang"}));
        set("title","���̻��̷���");
        set("long", 
                "���������̵��Ĵ󻤽̷����Ĵ��㡣\n"
                "��һ������ɫ��ȹ���ɶ����ˣ���˿�����������������Ȼ�˵����꣬��Ȼ��ζ�̴档\n");
        set("age", 43);
        set("nickname",MAG"��ɼ����"NOR);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 32);
        set("con", 20);
        set("dex", 30);
        
        set("max_qi",2000);
        set("max_jing", 1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 60);
          set("combat_exp", 400000);
    

        set_skill("sword",100);
        set_skill("dodge",100);
        set_skill("unarmed",100); 
        set_skill("literate",100);
        set_skill("force",100);
        set_skill("shenghuo-shengong",100);
        set_skill("qingfu-shenfa", 100);
        set_skill("liehuo-jian",100);
        set_skill("blade",100);
        //set_skill("shenghuo-quan",100);  

        map_skill("dodge", "qingfu-shenfa");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        //map_skill("unarmed","shenghuo-quan");

        create_family("����",34,"����");
        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query("int") < 24) {
                command("say " + RANK_D->query_respect(ob) +
                        "����Ƿ�ϣ���ѧ������һ���书��");
  return;
}
        if ((int)ob->query("dex") < 20) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;
 }
         command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
        command("recruit " + ob->query("id"));
        ob->set("title","���������������µ���");
}
