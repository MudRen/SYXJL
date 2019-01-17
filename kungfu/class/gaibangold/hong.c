// hong.c ���߹�
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "��ָ��ؤ");
	set("gender", "����");
	set("age", 75);
	set("long", 
		"������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_msg", ({
		"���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
		"���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
		"���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
	}));

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.xianglong" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry", ([
		"������" : "����������������\n",
		"ؤ��" : "����������������\n",
		"��ʦ" : "�����ȥ���������Ұ��ܶ��³�нţ�����Ϊʦ��\n",
	]));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2500);
	set("max_jing", 2500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 300);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	 
	set_skill("force", 170);             // �����ڹ�
	set_skill("huntian-qigong", 170);    // ��������
	set_skill("unarmed", 200);           // ����ȭ��
	set_skill("xianglong-zhang", 200);   // ����ʮ����
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 150);        // ��ң��
	set_skill("parry", 180);             // �����м�
	set_skill("staff", 170);             // ��������
	set_skill("dagou-bang", 150);        // �򹷰���
	set_skill("begging", 100);           // �л�����
	set_skill("checking", 100);          // ����;˵
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	map_skill("staff", "dagou-bang");
	
	create_family("ؤ��", 17, "����");

	setup();
	
	carry_object(__DIR__"yuzhu_zhang");
	carry_object(__DIR__"jiaohuaji");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
		command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
		return;
	}

	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "ؤ��") {
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");
		return;
	}

	command("recruit " + ob->query("id"));

	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
	
}

int accept_object(object who, object ob)
{
	object ob_yzz, me = this_object();

	if (ob->query("food_supply") <= 0)
		return 0;
	if ((string)ob->query("name") != "�л���") {
		command("say �Ͻл���" + (string)ob->query("name") + "ûʲô��Ȥ����");
		return 0;
	}
	if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
		command("say �Ͻл����ڱ��úܡ�");
		return 0;
	}
	command("say ����������������ԵĽл���ѽ��");
	command("eat ji");
	command("say �벻����СС��ͣ���˼ȴ��ϸ���͸�������ض�һ����");

	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "ؤ��") {
		command("say " + RANK_D->query_respect(ob) + "�㻹���������ʲô��");
		return 1;
	}

	if( ob_yzz = present("yuzhu_zhang", me) )
    {
		ob_yzz->move(who);
		write("������ȸ����Ҷ����ˣ����͸�����������ɡ�");
        return 1;
    }

	else
	{
		write("���������ò���ʱ���������Ѿ��������ˡ�");
        return 1;
	}

//	command("recruit " + who->query("id"));
	return 1;
}