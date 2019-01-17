#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "jiangyang dadao","dadao" }));
	set("nickname",HIW "�ӷ�"NOR);
	set("long", 
		"����ǰ��ʱ������ݼ�����Խ��������һ���ӷ���\n"
		"�������������ľ���ʧ�롣\n");
	set("gender", "����");
	set("age", 31);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 1800);
	set("max_jing", 1800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 250000);
	set("score", 10);

	set_skill("force", 135);
	set_skill("taiji-shengong", 135);
	set_skill("dodge", 135);
	set_skill("tiyunzong", 135);
	set_skill("unarmed", 135);
	set_skill("taiji-quan", 135);
	set_skill("parry", 135);
	set_skill("sword", 135);
        set_skill("taiji-jian",135);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
    	map_skill("sword", "taiji-jian");
    	

	
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: perform_action, "sword.sui" :),
		(: exert_function, "recover" :),
		(: random_move :)
	}) );

	setup();
	carry_object("/d/city/obj/changjian")->wield();
   	carry_object("/d/wudang/obj/greyrobe")->wear();

}
