// xiaobai.c  С��

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
	set_name("С��", ({ "xiao bai", "bai" }));
        set("nickname", HIW "Ц����" NOR);
	set("long", 
		"���Ǹ���Լ���������꣬����һ�������£������˸��˵ĸо������������·���\n"
		"����һ�ֵ����ĸо����������ۡ�\n");
	set("gender", "����");
	set("age", 22);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 140000);
	set("score", 30000);

	set_skill("force", 100);
   set_skill("unarmed",100);
       set_skill("wuji-shengong", 100);
	set_skill("dodge", 100);
	set_skill("bugui-bufa", 100);
	set_skill("parry",100);
	set_skill("sword", 120);
	set_skill("qingyi-jian", 120);
	set_skill("literate", 120);
	set_skill("strike",100);
	set_skill("fanyun-zhang",100);

       map_skill("force", "wuji-shengong");
	map_skill("dodge", "bugui-bufa");
	map_skill("parry", "qingyi-jian");
	map_skill("sword", "qingyi-jian");
	map_skill("strike", "fanyun-zhang");

	create_family("ɱ��¥", 3, "ɱ��");
	set("inquiry", ([
		"�ؼ�" : (: ask_me :),
	]));

	set("book_count", 1);


	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "sword.qingy" :),
		(: perform_action, "strike.yunkai" :),    
		(: exert_function, "recover" :),
	}) );

            set("no_get",1);
	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{

/*string *prename =
	 ({ "��" });
	string name, new_name;*/


        if ((int)ob->query("combat_exp") < 0) {
		command("say ɱ���������Դ������ӵ��£����Խ�������һ��Ҫ�ḻ��");
		return;
	}
	command("say �ðɣ��Ҿ��������ˡ�");
/*	       name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
       command("say ����ɱ�֣��͵�����ԭ����һ�У�ʦ���Ȱ���ĸ����ְɡ�\n");
	command("say ���ǡ��ơ��ֱ��ģ��ӽ��Ժ�������־ͽ���" + new_name + "��");
	command("smile");
	me->set("name", new_name);
	me->set("K_record", me->query("PKS") + me->query("MKS"));*/
       command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "shashou")
		ob->set("class", "shashou");

}


string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "ɱ��¥")
		return RANK_D->query_respect(this_player()) + 
		"���Ǳ��ŵ��ӣ��ؼ����ܽ����㣿";
	if (query("book_count") < 1)
		return "�������ˣ����彣���Ѿ����������ˡ�";
	add("book_count", -1);
	ob = new("/d/shashou/obj/qingyi-book");
	ob->move(this_player());
	return "�ðɣ��Ȿ�����彣�ס����û�ȥ�ú����С�";
}
