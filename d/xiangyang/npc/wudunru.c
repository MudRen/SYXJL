// wudunlu.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("�����", ({"wu dunru", "wu", "dunru"}));
	set("title", HIY"���������"NOR);
	set("gender", "����");
	set("age", 23);
	set("long", "���ǹ�������ӣ���ò�Ͱ���һ�쵽��Ц�Ǻǵġ�\n");
 	set("attitude", "peaceful");
	
	set("per", 24);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("inquiry", ([
		"����" : "������ʦĸ��\n",
		"����" : "������ʦ����\n",
	]));

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	
	set("combat_exp", 80000);
	set("score", 20000);
	 
	set_skill("force", 50);
	set_skill("tiangang-zhengqi", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	
	map_skill("force", "tiangang-zhengqi");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

