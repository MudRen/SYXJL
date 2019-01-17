// damo.c ��Ħ��ʦ
//modify by ronger 12/98

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��Ħ��ʦ", ({ "damo zushi", "damo" }));
	set("nickname", HIY"һέ�ɽ�"NOR);
	set("long", 
		"�����������ɿ�ɽ���桢�������ֵ�������ɮ��Ħ��ʦ��\n"
		"��һ���������ģ���ִ���ȡ�\n"
		"��ĸߴ��������꣬������⣬��ü�԰ס�\n");
	set("gender", "����");
	set("age", 500);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("class", "bonze");
	
	set("max_qi", 10000);
	set("max_jing", 5000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 100);
	set("combat_exp", 15000000);
	set("score", 5000000);

	set_skill("force", 500);
	set_skill("jiuyang-shengong", 500);
	set_skill("hunyuan-yiqi", 500);
	set_skill("dodge", 500);
	set_skill("shaolin-shenfa", 500);
	set_skill("cuff", 500);
	set_skill("sword", 500);
	set_skill("parry", 500);
	set_skill("finger", 500);
	set_skill("shaolin-shenfa", 500);
	set_skill("hand", 500);
	set_skill("strike", 500);
	set_skill("claw", 500);
	set_skill("staff", 500);
	set_skill("club", 500);
	set_skill("blade", 500);
	set_skill("whip", 500);
	set_skill("damo-jian", 500);
	set_skill("fumo-jian", 500);
	set_skill("pudu-zhang", 500);
	set_skill("wuchang-zhang", 500);
	set_skill("jingang-quan", 500);
	set_skill("buddhism", 500);
	set_skill("riyue-bian", 500);
	set_skill("literate", 500);
	set_skill("ranmu-daofa", 500);
	set_skill("weituo-chu", 500);


	map_skill("force", "jiuyang-shengong");
	map_skill("staff", "pudu-zhang");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "pudu-zhang");
	map_skill("sword", "damo-jian");
	map_skill("whip", "riyue-bian");

        create_family("������", 1, "��ɽ��ʦ");
	set("class", "buddhism");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
//		(: perform_action, "whip.chan" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/shaolin/obj/chanzhang")->wield();
	carry_object("/d/shaolin/obj/damo-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}
	if ((int)ob->query_skill("hunyuan-yiqi", 1) < 200) {
		command("say �����������ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ�����ڹ��϶��µ㹦��");
		return;
	}
	if ((int)ob->query_skill("buddhism", 1) < 180) {
		command("say ����֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("say �������ķ����棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if ((int)ob->query_skill("dodge", 1) < 200) {
		command("say ���Ṧ���棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if ((int)ob->query_skill("shaolin-shenfa", 1) < 200) {
		command("say ���Ṧ���棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if ((int)ob->query_skill("force", 1) < 200) {
		command("say ���ڹ����棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if ((int)ob->query_skill("parry", 1) < 200) {
		command("say �ڻ��������棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if (ob->query_int() < 45) {
		command("say ���¶���һ��Ե�֡�");
		command("say " + RANK_D->query_respect(ob) + "�����Ե��������ذɡ�");
		return;
	}
         if (ob->query("MKS") > 20 ) {
		command("say ���¶���һ��Ե�֡�");
		command("say " + RANK_D->query_respect(ob) + "�����Ե��������ذɡ�");
		return;
	}
        if (ob->query("PKS") > 0 ) {
		command("say ���¶���һ��Ե�֡�");
		command("say " + RANK_D->query_respect(ob) + "�����Ե��������ذɡ�");
		return;
	}
//	if ( ( ob_fam["generation"] + 35 ) == (my_fam["generation"]) )
	if ( ob->query("family/generation") == 36 )
	{
	//	if ( ob->query("luohan_winner") )
	//	{	
			command("say ���Ĵ���֮�꣬�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

			name = ob->query("name");
			new_name = "��" + name[2..3];
			ob->set("name", new_name);
			ob->set("family/generation", 35);

			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɶ��ֱ��޺�֮һ !");
			command("recruit " + ob->query("id"));
		
		
	}

	return;



}
