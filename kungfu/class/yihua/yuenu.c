// /NPC huawuque.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��ū", ({ "yue nu", "yue", "nu" }));
	set("long",
	    "����һ����ʮ�������Ů��,�Ʋ����˼�֮��,\n"+
	    "�������, �������. \n"+
	    "��һ���������µĽ�����, ��ʹ�����Լ��ֽ���.\n"+
	    "�����ƻ��������ָ���,�ƻ���δ����ϣ��.\n");
	set("title", "�ƻ���������Ů");
	set("gender", "Ů��");
	set("age", 20);
	set("nickname", HIR "����������Ů" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 2000);
    set("max_jing", 3000);
    set("neili", 5000);
    set("max_neili", 5000);
	set("jiali", 100);

	set("combat_exp", 3000000);
	set("score", 200000);
	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("sword",250);
        set_skill("literate",250);

	set_skill("jueqing-zhang",250);
	set_skill("mingyu-shengong",250);
	set_skill("yifeng-jian",250);
        set_skill("yihua-jiemu",250);

	map_skill("unarmed", "jueqing-zhang");
	map_skill("force", "mingyu-shengong");
	map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
        map_skill("sword","yifeng-jian");

	create_family("�ƻ���",2, "��Ů");
	setup();
    carry_object("/d/yihua/obj/jinlvyi")->wear();
        carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",50);
}

void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="Ů��")
   {
		message_vision("��ū��Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ����������ūΪʦ���²�Ҫ����˵��Ȼ�ù���֪���˾Ͳ�������.��\n",ob);
       command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "yihuashinv")
			ob->set("class", "yihuashinv");
       return;}
   else
      {
		message_vision("��ū�����㿴�˰���,˵�������㻹�ǿ��߰�!��Ȼ�ù����������ҿɱ�������.��\n",ob);

   if ((int)ob->query_skill("mingyu-shengong", 1) < 100) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö�����ڤ����,��Ȼ�ù���֪���Ҳ��ܰ���!");
		return;
	   }  
       return;}
}
