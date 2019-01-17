inherit NPC;

string ask_me_1(string name);
string ask_me_2(string name);
string ask_me_3();
string ask_me_4();
string ask_me_5();

void create()
{
	set_name("����", ({"gui yan",	"yan",}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 26);
	set("int", 26);
	set("con", 26);
	set("dex", 28);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 150000);
	set("score", 10000);

	set_skill("force", 120);
	set_skill("kurong-changong", 120);
	set_skill("dodge", 110);
	set_skill("duanjia-shenfa", 110);
	set_skill("sword", 85);
	set_skill("duanjia-jian", 85);
	set_skill("parry", 95);
	set_skill("buddhism", 100);
	set_skill("literate", 90);
        set_skill("unarmed",120);
	map_skill("force", "kurong-changong");
	map_skill("dodge", "duanjia-shenfa");
	map_skill("sword", "duanjia-jian");
	map_skill("parry", "duanjia-jian");

	prepare_skill("sword", "duanjia-jian");

	create_family("������", 7, "�����");
        set("inquiry", ([
		"������" : (: ask_me_1, "huwan" :),
		"������" : (: ask_me_1, "huyao" :),
		"Ƥ����" : (: ask_me_1, "shoutao" :),
		"ƤΧ��" : (: ask_me_1, "weibo" :),
		"��ָ��" : (: ask_me_1, "zhitao" :),
		"ɮЬ"   : (: ask_me_1, "sengxie" :),
                "������" : (: ask_me_2, "beixin" :),	
		"��ҩ" :    (: ask_me_3 :),
		"С����" :    (: ask_me_4 :),
		"�󻹵�" :    (: ask_me_5 :)
	    ]));

	set("huju_count", 50);
	set("beixin_count", 5);

	setup();
        carry_object("/clone/weapon/changjian")->wield();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�";

	if (query("huju_count") < 1)
		return "��Ǹ�������ò���ʱ�򣬷����Ѿ������ˡ�";

	ob = new(__DIR__"obj/" + name);
	ob->move(this_player());

	add("huju_count", -1);

	message_vision("���̸�$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�����Ҫ��ס������ֻ�ɷ������䣬����ƾ�˷������ˡ�";
}

string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (query("beixin_count") < 1)
		return "��Ǹ�������ò���ʱ�������Ѿ������ˡ�";

	ob = new(__DIR__"obj/" + name);
	ob->move(this_player());

	add("beixin_count", -1);

	message_vision("���̸�$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�����Ҫ��ס�����������Ƿ��������ƾ�˷������ˡ�";
}

string ask_me_3()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

	if (  present("jin chuangyao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

	if (query("jin_count") < 1) return "�Բ��𣬽�ҩ�Ѿ�������";

	ob = new(__DIR__"obj/jinchuang-yao");
	ob->move(this_player());

	add("jin_count", -1);

	message_vision("$N���һ����ҩ��\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";

}

string ask_me_4()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

	if (  present("xiaohuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

	if (query("xiao_count") < 1) return "�Բ���С�����Ѿ�������";

	ob = new(__DIR__"obj/xiaohuan-dan");
	ob->move(this_player());

	add("xiao_count", -1);

	message_vision("$N���һ��С������\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";

}

string ask_me_5()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

      if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

	if (  present("dahuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";

	if (query("da_count") < 1) return "�Բ��𣬴󻹵��Ѿ�������";

	ob = new(__DIR__"obj/dahuan-dan");
	ob->move(this_player());

	add("da_count", -1);

	message_vision("$N���һ�Ŵ󻹵���\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";

}



