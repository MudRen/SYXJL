// jinmao-shiwang.c ��ëʨ��
// by tony  97/7
#include <ansi.h>
inherit NPC;

object ob = this_object();
void create()
{
        set_name("л ѷ",({"xie xun","xie","shiwang"}));
        set("title","���̻��̷���");
        set("long", 
                "���������̵��Ĵ󻤽̷�����������\n"
                "��һͷ�����Ʈ�ڣ���ֻ�۾����ݽ��գ�������ä�ˣ�������δ�ϣ�׳־δ�꣡\n");
        set("age", 56);
        set("nickname",HIY"��ëʨ��"NOR);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 35);
        set("int", 20);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi",4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 75);
        set("combat_exp", 880000);


        set_skill("sword",180);
        set_skill("dodge",180);
        set_skill("unarmed",180); 
        set_skill("literate",90);
        set_skill("force",190);
        set_skill("liehuo-jian",180);
        set_skill("qingfu-shenfa", 180);
        set_skill("blade",180);
        set_skill("parry",180);
        set_skill("qishang-quan",180);
        set_skill("cuff",180);
        set_skill("hunyuan-yiqi",190);
        set_skill("shenghuo-shengong",180);
      

        map_skill("dodge", "qingfu-shenfa");
        map_skill("force","hunyuan-yiqi");
        map_skill("sword","liehuo-jian");
        map_skill("cuff","qishang-quan");
        map_skill("parry","liehuo-jian");

        create_family("����",34,"����");
        set("inquiry", ([
"����" : "��������ʥ�����̵�34����ëʨ����лѷ��\n",
"Բ��" : "Բ������������Һ޲��ܺ�����Ѫ����������! \n",
"���޼�" : "�Һܾ�û�м����ҵĺ����ˣ����ر�ϲ���ҵĽ�ͷ����\n",
        ]));

        setup();
       carry_object("/d/city/obj/changjian")->wield();
        
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
          if ((int)ob->query("shen") <10000) {
                command("say " + RANK_D->query_respect(ob) +
          "����޵ľ��Ǽ��ս�թ�Ķ��,�������̫��,�������ҵĵ���.");
                return;
          }
         command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
        command("recruit " + ob->query("id"));
        ob->set("title","���̽�ëʨ����ͽ");
}
int accept_object(object ob, object obj)
{
    object me = this_object();
          if (obj->query("id") == "ren tou" )
     
        {
         command("say ��ɱԲ���Ϊ�ұ�����!���ë����ȥ�������Ǻ����ɣ�\n");
         remove_call_out("destroying");
         call_out("destroying", 1, me, obj);
         ob = new("/d/mj/obj/jinmao");
         ob->move(this_player());
        
        return 1;
        }
      
        command("smile");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;

}
