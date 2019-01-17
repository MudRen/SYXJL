//yang.c ���
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("���",({"yang guo","yang","guo"}));
        set("title","��Ĺ����");
        set("nickname",HIY"������"NOR);
        set("long", "�������������µ���������һ�۵����ڲ�ȥһ����Ӣ�ۺ�����\n");
        set("age", 35);
        set("attitude", "friendly");
        set("shen", 1000000);
        set("per", 30);
        set("str", 28);
        set("int", 28);
        set("con", 30);
        set("dex", 29);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("eff_jingli", 3000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 2000000); 
        set_skill("sword",200);
        set_skill("dodge",200);
          set_skill("unarmed",200);
          set_skill("cuff",200);
        set_skill("strike",200);
        set_skill("force", 200);
        set_skill("yunu-shenfa", 200);
        set_skill("xuantie-jianfa", 200);
        set_skill("anran-xiaohunzhang", 200);     
        set_skill("quanzhen-jianfa",180);
        set_skill("tianluo-diwang", 180);
        set_skill("parry", 200);
        set_skill("yunu-xinjing",200);
        set_skill("literate", 150); 
        map_skill("force", "yunu-xinjing");        
        map_skill("sword","xuantie-jianfa");
        map_skill("dodge", "yunu-shenfa");
        map_skill("parry", "anran-xiaohunzhang");        
        map_skill("strike", "anran-xiaohunzhang");        
        prepare_skill("strike","anran-xiaohunzhang");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "sword.haichao" :),
        }));
    
        create_family("��Ĺ��",3,"������");
        set("inquiry", ([
           "��Ĺ" : "���ջ�ɽ����Ӣ�۾��������������ڴ��������꣬�������£�����
�����ڴ˳���һ�����������ӣ�",
           "������" : "������������������֮��˽�ɱ�����أ��������ô˽����ֽ�����
���زش˽���һ����",
           "С��Ů" : "�������Ұ��ޣ�������������",
        ]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/gumu/obj/buxue1")->wear();
        carry_object("/d/gumu/obj/pao1")->wear();         
}

void attempt_apprentice(object ob)
{
     mapping fam = ob->query("family");
      if (!fam || fam["family_name"] != "��Ĺ��"){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }       
      if((int)ob->query_skill("yunu-xinjing", 1) < 120) {
                command("say �ڹ��ǹ�Ĺ�书֮������"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                return;
                }   
      if((int)ob->query_int() < 30 ) {
                command("say �ҵ��书��Ҫ���ߵ����Բ���ѧ�ᡣ");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say "+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
                }
      if(ob->query("gender") != "����") {
                command("say �ҿ�ֻ����ͽ����ȥ�������������԰ɡ�");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");         
        command("chat ��Ĺ�书���ֽ�����"+ ob->name() +"�ɱ���Ϊʦ�������ˣ�");
        command("chat* pat " + ob->query("id"));
        command("recruit " + ob->query("id"));
        ob->set("title","��Ĺ��������´���");
        ob->set("class","sworder");
}

void leave()
{
   message("vision", name() + "ʧ���Ŀ��˿������ĵ����ˡ�\n", environment(), this_object() );
   destruct(this_object());
}

void relay_whisper(object me, string msg)
{
   if (query("owner_id") != me->query("id"))
   {
     message_vision((string)this_object()->query("name") 
        + "����$N�����һ����\n", me);
     return;
   }
   
   message_vision((string)this_object()->query("name") + "����$N���˵�ͷ��\n", me);
   if (msg)
   {
     remove_call_out ("relaying");
     call_out ("relaying", 1+random(3), msg);
   }
}

void relaying (string msg)
{
   command (msg);
}

void init()
{       
   object me=this_player();
   object owner;

   ::init();

   if ( (string)this_object()->query("owner_id") == (string)me->query("id") )
   {
     this_object()->set_leader(me);
   }

   if( this_object()->query("owner_id") != 0 )
   {
     owner = find_player( (string)this_object()->query("owner_id") );
     if( !owner ) owner=find_living( (string)this_object()->query("owner_id") );
     if( !owner )
     {
        remove_call_out ("leave");
        call_out ("leave", 1);
     }
   }
}
