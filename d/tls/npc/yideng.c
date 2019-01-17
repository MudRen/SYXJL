#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("һ�ƴ�ʦ",({"yideng dashi","yideng","dashi"}));
    set("nickname", HIY "�ϵ�" NOR );
    set("title", "������ǰ������");
    set("gender", "����");
    set("age", 42);
    set("long", 
 "�����������µĿ�ɽ��ʦ���������ڵ��������������˵�λ���ͳ��������˺��У�\n");
    set("attitude", "peaceful");
    set("str", 45);
    set("int", 40);
    set("con", 50);
    set("dex", 40);

    set("inquiry", ([
        "������"   : "�����˲��ǵ�����һ���֣����������Ļ����书������Ϊ��Ҫ���������� \n",
        "��������" : "������к��ã�������...���Ǹ��Һú�ѧ�ɣ�����\n",
        "��ʦ" :"���Ѿ��ÿ���ȥ�����ҵ���ȥ�ˣ���ȥ�������ʺ��ˡ�",
]));
        set("max_qi", 10000);
      set("qi",10000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jiali", 600);
        set("combat_exp", 3000000);
        set("score", 4000000);

      set_skill("force", 300);             
      set_skill("finger", 250);            
      set_skill("kurong-changong", 300);   
      set_skill("dodge", 250);             
      set_skill("tiannan-bufa", 250);    
      set_skill("parry", 250);             
      set_skill("yiyang-zhi", 250);        
      set_skill("literate",250);
      set_skill("sword", 250); 
      set_skill("duanjia-jian", 250);     
      set_skill("liumai-shenjian", 250); 
      set_skill("jinyu-quan", 250);
      set_skill("unarmed", 250);      
      set_skill("buddhism", 300);
      set_skill("literate", 200);
      map_skill("unarmed" , "jinyu-quan");
      map_skill("force"  , "kurong-changong");
      map_skill("sword", "duanjia-jian");
      map_skill("finger" , "liumai-shenjian");
      map_skill("dodge"  , "tiannan-bufa");
      map_skill("parry"  , "liumai-shenjian");
      map_skill("finger","liumai-shenjian");
      prepare_skill("finger","liumai-shenjian");
  
      create_family("������", 4, "����");
     
      set("chat_chance_combat", 100);
      set("chat_msg_combat", ({
                (: perform_action, "finger.tan" :),
                (: perform_action, "finger.feng" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.liujian" :),
                (: exert_function, "recover" :),
        }) );
     setup();
    carry_object(__DIR__"obj/sengxie")->wear();
    carry_object(__DIR__"obj/sengrobe")->wear();

}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("score") < 200 && ob->query("family/master_id")=="yideng dashi")
        {
                command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","������" + RED + "��ͽ" NOR);
        }
}

void attempt_apprentice(object ob)
{
        string name,new_name; 
        if((!ob->query("family") || ob->query("family")["family_name"]!="������"))
        {
                command("say ����������ӣ���ˡ���Ĳ������㡣");
                
                return ;
        } 
        if ((string)ob->query("class") != "bonze") {
                command("say ���Ĳ����׼ҵ��ӣ�ʩ����ذɡ�");
                
                return ;
        }        if ((int)ob->query_skill("kurong-changong", 1) < 220) {
                command("say �������������ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ���ڿ��������϶��µ㹦��");
                return ;
        } 
        if ((int)ob->query("score") <500) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }        if ((int)ob->query("shen") <700000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }
        if ((int)ob->query_skill("buddhism", 1) < 230) {
                command("say ����֮�ˣ�����Ϊ�ȣ����������˷��ŵմ�������ѧ�÷�ҵľ���ɡ�");
                command("say �������ķ����棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return ;
        }
        if ((int)ob->query_skill("yiyang-zhi", 1) < 200) {
                command("say ���ŵ������������Զμ�һ��ָΪ�����ġ�");
                command("say ������" + RANK_D->query_respect(ob) +
                        "���һ��ָ���������");
                return ;
        } 
        if((string)this_player()->query("family/master_id")!="ku rong" )
        {
                command("say �㻹����ȥ�ҿ���ʦֶѧϰ�ɡ�\n");      
                return ;
        }                                     
        command("say ����,����...����ɵö���ù�");
        command("party ��ɮ����һͽ��,����Ժ�ú��д衣");
        command("recruit " + ob->query("id"));
        name = ob->query("name");     
        new_name = "��" + name[2..3];
        ob->set("name", new_name);
        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����¿��ֱ����� !");
        
        return ;
}
