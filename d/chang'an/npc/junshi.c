// bing.c �ٱ�

inherit NPC;

void create()
{
        set_name("��ʿ", ({ "jun shi", "shi" }));
	set("age", 22);
	set("gender", "����");
         set("long", "һ������ĳ����ؾ���\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

//	if (random(2) == 1) {
//		set("chat_chance", 10);
//		set("chat_msg", ({
//			(: random_move :),
//		}));
//	}

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
                "��ʿ����˵���������˾�������,�����˵�һ�ɲ���Я��������ǣ�\n",
	}));
	setup();
this_object()->carry_object("/d/city/npc/obj/gangdao")->wield();
this_object()->carry_object("/d/city/npc/obj/junfu")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
