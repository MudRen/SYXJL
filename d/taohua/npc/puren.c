// puren.c

inherit NPC;

void create()
{
	set_name("����", ({ "pu ren","ren","pu" }) );
	set("gender", "����" );
	set("age", 30);
	set("long", "һ��������������,����С����������ŵ���ʰ������\n");
	set("combat_exp", 3000);
	set("str", 17);
	set("dex", 16);
	set("con", 18);
	set("int", 20);
	set("attitude", "peacely");
	set("max_qi", 150);
	set("max_jing", 150);

	set_skill("force", 15);
	set_skill("dodge", 15);
	set_skill("unarmed", 15);
	set_skill("parry", 15);


	setup();
	carry_object("/d/taohua/obj/cloth")->wear();

}

