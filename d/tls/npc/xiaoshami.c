inherit NPC;

void create()
{
	set_name("Сɳ��", ({ "xiao shami","shami"}) );
	set("gender", "����" );
	set("class", "bonze");
	set("age", 15);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("qi", 500);
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 10);
	set("combat_exp", 8000);
	set("score", 1000);

	set_skill("force", 50);
	set_skill("kurong-changong", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("jinyu-quan", 50);
        set_skill("dodge", 50);
        set_skill("duanjia-shenfa", 50);

        map_skill("dodge", "duanjia-shenfa");
        map_skill("parry", "jinyu-quan");
        map_skill("force", "kurong-changong");
	map_skill("unarmed","jinyu-quan");

        setup();
}