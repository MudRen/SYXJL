// kid.c

inherit NPC;

void create()
{
	set_name("СŮ��",({ "little girl","girl" }) );
        set("gender", "Ů��" );
        set("age", 7);
        set("long", "���Ǹ���������СŮ����\n");
        set("combat_exp", 50);
	set("shen_type", 1);
	set("str", 10);
	set("dex", 12);
	set("con", 15);
	set("int", 11);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

