// kunlun-dizi1.c (kunlun)



inherit NPC;



void create()

{

	set_name("�����ɵ���", ({ "dizi"}));

	set("long",

		"��������������Բ���ƺ�����һ���书��\n");

	set("gender", "����");

	set("age", 17);

	set("attitude", "heroism");

	set("shen_type", 1);

	set("str", 25);

	set("int", 20);

	set("con", 20);

	set("dex", 23);



	set("max_qi", 200);

	set("max_jing", 150);

	set("neili", 200);

	set("max_neili", 200);

	set("jiali", 5);

	set("combat_exp", 3000);

	set("score", 400);



	set_skill("dodge", 20);

	set_skill("strike", 20);



	create_family("������", 5, "����");

	setup();

	carry_object("/d/kunlun/obj/cloth")->wear();

}





