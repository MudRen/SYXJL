// yudaiyan.c ����� 

inherit NPC;

void create()
{
set_name("�����", ({ "yu daiyan", "yu" }));  
set("nickname","�䵱����");
	set("long", 
		"�����������������������ҡ�\n"
		"��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
		"���������ʮ������ݳ����񵭳�ͣ���Ĭ���ԡ�\n");
	set("gender", "����");
	set("age",43);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 60000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 80);
	set_skill("dodge", 80);
	set_skill("tiyunzong", 60);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 100);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("taiji-jian", 60);
	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");

	create_family("�䵱��", 2, "����");
	setup();
//	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}


