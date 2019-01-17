#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name(MAG"������"NOR, ({ "fengyuyun", "wry" }));
        set("nickname", HIG"��"HIW"��"HIB"��"HIY"��" NOR);
        set("long", 
                "���������䴫�ŵ����ӣ��ŷ����꿴��¥����ʦ���š�\n");
        set("gender", "Ů��");
        set("age", 80);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set_skill("sword", 500);       
        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 100);
        set("combat_exp", 2000000);
        set("score", 500000); 

        create_family("�ŷ����꿴��¥", 1, "��ɽ��ʦ");
        set("class", "sword");

        set("chat_chance_combat", 40);
        set("chat_msg", ({
             "������̾�˿�����������֪����ʦС����ںη�\n",
             "������˵��������֪�ŷ����꿴��¥�����ɺã��п�Ҫȥ�������ǡ�\n",
                (: random_move :)
 }));       
        set("inquiry", ([
                "�ŷ����꿴��¥" : "СŮ�Ӿ��Ǵ�¥�Ŀ�ɽ��ʦ��\n",
                "��ʦ" : "�������ɺ���ԨԴ����̸��ʦ����\n",
        ])); 
       setup();
        carry_object("/u/wry/obj/wrysword")->wield();
        carry_object("/clone/misc/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="�ŷ����꿴��¥" ) 
       {        command("say ������ɣ���Ҳ���ŷ����꿴��¥��һ�����š�");
                command("say " + RANK_D->query_respect(ob) + "���������������¥��"); 
                return;
        }

        command("chat*jump");
        command("chat ���ֶ���һ������Ү��������");
        command("chat* pat " + ob->query("id"));
        
        command("recruit " + ob->query("id"));
        ob->set("title",HIW"�ŷ����꿴��¥"MAG"����"HIW"���ڵ���"NOR);

}

int accept_fight(object me, object ob)
{   ob=this_player();
   command("say " + RANK_D->query_rude(ob) + "ɱ��̫�أ��ֻ������ѣ�\n");
   return 0;
}

void die()
{

        if( environment() ) {
        command("sigh");
        }

        destruct(this_object());
}




