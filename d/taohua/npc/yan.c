//yan.c
inherit NPC;
void greeting(object);
void init();
void create()
{
       set_name("������", ({ "liuru yan","liu" }) );
	set("gender", "Ů��" );
	set("age", 20);
	set("long", "�������һ����ĳ�ʦ���Ǹ���ò毺õ�Ů�ӣ� ����������\n"
	    "������ᣬ ������ס�\n");
	set("combat_exp", 10000);
	set("str", 20);
	set("dex", 22);
	set("con", 20);
	set("per", 24);
	set("attitude", "friendly");
	setup();
	carry_object("/d/city/npc/obj/pink_cloth")->wear();
	add_money("silver",50);
}
void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	object obn;
	if( !ob || environment(ob) != environment() ) return;
	if(((string)ob->query("family/family_name")=="�һ���")&&(random(3)==1))
	{
		say("������Ц������˵������λ" + RANK_D->query_respect(ob)
		+ "�����˰ɣ����ò͡�\n");
		obn=new("/d/taohua/obj/gao");
		obn->move(environment(ob));
		obn=new("/d/taohua/obj/cha");
		obn->move(environment(ob));
	}
	else 
	say("������΢΢һЦ��˵������λ" + RANK_D->query_respect(ob)
		+ "����ӭ���ιۣ��ɲ�Ҫ͵��Ӵ��\n");
	return;
}