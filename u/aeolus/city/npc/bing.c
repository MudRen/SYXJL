// bing.c �ٱ�

inherit NPC;

void create()
{
	set_name("�ٱ�", ({ "guan bing", "bing" }));
	set("age", 22);
	set("gender", "����");
	set("long", "��Ȼ�ٱ������ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������\n");
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
		"�ٱ��ȵ����󵨵��񣬾����췴���ɣ�\n",
		"�ٱ��ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
	}));
	setup();
this_object()->carry_object("/d/city/npc/obj/gangdao")->wield();
this_object()->carry_object("/d/city/npc/obj/junfu")->wear();
}


void init()
{
        object ob;
        ::init();
        if (!living(this_object()))     return;
        if (interactive(ob = this_player())){
                if (    (int)ob->query_condition("killer") ){
                        command("say �����������ү��ס�ˣ�ɱ�˷��������ӣ�\n");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
                if( this_player()->query_temp("illicit") ){
                        command("say ���ɣ������ӣ�\n");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
        }
        add_action("do_kill","kill");
        add_action("do_kill","hit");
}
int do_kill(string arg)
{
        object ob;
        if (living(this_object()) && this_object()->id(arg)){
                command("say ���ܣ��ֵ��ǣ��ϣ�");
                if (ob=present("wu jiang",environment()))
                        ob->kill_ob(this_player());
                if (ob=present("guan bing",environment()))
                        ob->kill_ob(this_player());
        }
        return 0;
}
int accept_fight(object me)
{
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
