// Room: /d/wuguan/npc/lxq.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("�˷���", ({ "lang fanyun","lang","lxq"}) );
	set("gender", "����" );
	set("age", 27);
	set("long",
		"�������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query("mud_age")<1000)	
	{
		command("hi " + ob->query("id"));
		command("say ������˵һ˵nick��describe���\n");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say nick��������д���Լ��Ĵºŵģ���describe������д�Լ���������\n");	
	command("say nick��describe����һ����nick�Ǵºţ��Ƿ���������ǰ��ġ�\n");			
	command("say ����describeд��������Ҫ����look���ܿ����ġ�\n");	
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say Ȼ������������Ҫ�����save��quit��\n");	
	command("say save���Ǵ浵������ϵͳ�ᶨʱ�Զ��浵������һ�����������á�\n");	
	command("say quit���˳���Ϸ���˳���Ϸ��ʱ��������Щ��Ʒ�ᶪ�µģ�������һ�¡�\n");							
}

