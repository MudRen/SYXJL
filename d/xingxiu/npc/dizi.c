//dizi.c ����
//by QingP

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({ "dizi" }));
	set("long", 
                "����һ�������ɵ��ӡ�\n"
		"����������ʮ�����ģ����\n");
	set("gender", "����");
	set("age", 21 + random(7));
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 21);
	set("int", 22);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 270);
	set("max_jing", 210);
	set("neili", 200);
	set("max_neili", 200);
	set("combat_exp", 20000 + random (7000));

	set_skill("force", 45);
	set_skill("dodge", 45);
	set_skill("strike", 40);
	set_skill("parry",50);
	set_skill("staff",50);

	create_family("������", 3, "����");

	setup();
  	carry_object(__DIR__"obj/tiegun")->wield();
	carry_object("/clone/misc/cloth")->wear();
}