// yapu.c

inherit NPC;

void create()
{
	set_name("����", ({ "ya pu","ya","pu" }) );
	set("gender", "����" );
	set("age", 40);
	set("long", "һ���������������ˡ�\n");
	set("combat_exp", 10000);
	set("str", 24);
	set("dex", 20);
	set("con", 23);
	set("int", 20);
	set("attitude", "peacely");
	set("max_qi", 200);
	set("max_jing", 200);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 22);
	set_skill("parry", 20);


	setup();
	carry_object("/d/taohua/obj/cloth")->wear();

}

