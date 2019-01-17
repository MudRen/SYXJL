// /NPC gongzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�ƻ�������", ({ "gong zhu", "gong", "zhu" }));
	set("long",
	    "�����ǡ��ƻ������Ŀ�ɽ��ʦ.\n"+
	    "���ñ�������ɴ������,����͸���ǿ���ɴ����Ȼ��ϡ�ɼ�\n"+
	    "����ɫɷ��,�Բ����˼����˿�����,�㲻�ɵö࿴��һ��.\n");
	set("title", "�ƻ�������");
	set("gender", "Ů��");
	set("age", 36);
	set("nickname", HIR "ɱ�����¸��ĺ�" NOR);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 55);
	set("int", 35);
	set("con", 40);
	set("dex", 20);

	set("qi", 50000);
	set("max_qi", 50000);
	set("jing", 14000);
	set("max_jing", 14000);
	set("neili", 150000);
	set("max_neili", 50000);
	set("jiali", 200);

	set("combat_exp", 900000000);
	set("score", 2000000);
	set_skill("force", 950);
	set_skill("unarmed", 950);
	set_skill("dodge", 900);
	set_skill("parry", 950);
	set_skill("sword",950);
        set_skill("literate",1000);

	set_skill("yihua-force",950);
	set_skill("yifeng-jian",950);
        set_skill("yihua-jiemu",900);

	map_skill("force", "yihua-force");
	map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
        map_skill("sword","yifeng-jian");

	create_family("�ƻ���",1, "����");
set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yifeng" :),
			}) );
	setup();
	carry_object("/d/city/obj/changjian")->wield();
        carry_object("/u/skinys/yihua/obj/jinlvyi")->wear();
       
}

void attempt_apprentice(object ob)
{
   
   if ((string)ob->query("gender")!="Ů��")
           {
 		command("heihei");
                command("say ����һ����޵ľ�������,��ȥ����!");
                kill_ob(this_player());
                command("perform yifeng");
		return;
	   }
   if ((int)ob->query_skill("dodge", 1) < 100) 
           {
		command("say " + RANK_D->query_respect(ob) + "���������!");
		return;
	   }
   if ((int)ob->query_skill("yihua-force", 1) < 330) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������ƻ��ķ���");
		return;
	   }
   if ((int)ob->query_skill("yifeng-jian", 1) < 130) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������Ʒ罣����");
		return;
	   }
   if (ob->query_per() < 40) 
      	   {
		command("say ƾ����ģ���������Ϊʦ.");
		return;
	   }
   if (ob->query_con() < 40) 
      	   {
		command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
		return;
	   }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "chuanren")
     ob->set("class", "chuanren");
   return;
}

void init()
{
	object ob;

	::init();

	ob = this_player();

	if (interactive(ob) && (!ob->query("gender") || ob->query("gender")!="Ů��"))
	{
			command("hehe");
			command("say ��ƽ�����������ˣ�ȥ���ɣ�\n");
			remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
                        command("perform yifeng");
	}
	else if(ob->query("gender")=="Ů��")
	{
	command("smile");
	command("say ���������㲻�����˲�Ȼ������úܲҡ�");
	}
}