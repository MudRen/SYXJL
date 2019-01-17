inherit NPC;

void create()
{
	set_name("����ɮ", ({ "huta seng","seng"}) );
	set("gender", "����" );
	set("class", "bonze");
	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 20);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 100);
	set_skill("kurong-changong", 100);
	set_skill("dodge", 100);
	set_skill("duanjia-shenfa", 100);
	set_skill("parry", 100);
	set_skill("finger", 100);
	set_skill("yiyang-zhi", 100);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "duanjia-shenfa");
	map_skill("parry", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");	
	set("inquiry" ,([
	"������" : "����������֮����ԭ��������������ʩ������ȥ�����𣿡�\n",
	"����" : "��ʩ��Ҳ��֪�����ǵ�������������ѵ�����˼��˼һ�£���\n",
	]));

	setup();
}

int accept_object(object who, object ob)
{
        who = this_player();
        if (ob->query("money_id") && ob->value() >= 10000) 
		{
		message_vision("����ɮ���ĵذ�$N������������\n", who);
               who->move("/d/tls/tading");
		return 1;
		}
	else
		{
		message_vision("����ɮ˫�ֺ�ʮ�����������������ӷ𣡡�\n");
		return 0;
		}
	return 0;
}
