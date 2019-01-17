// wusantong.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("����ͨ", ({"wu santong", "wu", "santong"}));
	set("gender", "����");
	set("age", 55);
	set("long", "һ�ƴ�ʦ���Ĵ����֮һ����������Э�������������سǡ�\n");
 	set("attitude", "peaceful");
	
	set("per", 17);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	
	set("combat_exp", 100000);
	set("score", 20000);
	 
	set_skill("force", 50);
	set_skill("kurong-changong", 50);
	set_skill("finger", 50);
	set_skill("yiyang-zhi", 50);
	set_skill("cuff", 50);
	set_skill("jinyu-quan", 50);
	set_skill("dodge", 50);
	set_skill("tiannan-bufa", 50);
	set_skill("parry", 50);
	
	map_skill("force", "kurong-changong");
	map_skill("cuff", "jinyu-quan");
	map_skill("dodge", "tiannan-bufa");
	map_skill("parry", "jinyu-quan");
	prepare_skill("cuff", "jinyu-quan");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}
