// girl2.c

inherit NPC;

void create()
{
	set_name("Ů��",({ "girl" }) );
        set("gender", "Ů��" );
        set("age", 12);
        set("long", "���Ǹ���Ů����Ȼֻ��ʮ�������꣬����Ѿ���ʼ������\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 80);
	set("shen_type", 1);
        set("str", 13);
        set("dex", 16);
        set("con", 18);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

