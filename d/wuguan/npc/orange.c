// Room: /d/wuguan/npc/orange.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("����", ({ "ju zi","orange"}) );
	set("gender", "����" );
	set("age", 22);
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
		command("say ���ã������Ǹ��������һЩ����ð��ָ��ģ����ָ�̡�\n");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ���ȣ���������һ��askָ�ask��������NPC�����һ�����\n");	
	command("say ����Ϸ�У��кܶ�NPC������ask����һЩ��Ҫ��Ϣ��\n");			
	command("say �����ǣ�ask <NPCӢ������> about [����]��\n");	
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ���ڸ���˵һ˵����look��iָ�\n");	
	command("say look���ǿ�����˼�������ǣ�look [(���˻���Ʒ)]���ɼ�дΪl��\n");	
	command("say ���������l��һ���Լ����ڳ�����������Ҳ����l ju zi �����ҡ�\n");							
	command("say ���������i�����ܿ����Լ����ϵĶ��������˸���ͨ��ֻ��һ���·�����\n");					
	call_out("teach3",7,ob);
}



void teach3(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say Ȼ������˵һ˵get��drop��giveָ�\n");	
	command("say get �Ǽ���ĳ����Ʒ��drop���ӵ�ĳ����Ʒ��give�Ǹ����˶�����\n");	
	call_out("teach4",5,ob);
}	




void teach4(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ����Ҫ����buy��sell��open��close�ȳ��õ�ָ�\n");	
	command("say buy�ܹ��ڵ����뵱��������sell�ܹ��ڵ��������Լ��Ķ�����\n");
	command("say open��close�ֱ��Ǵ���ر��Ż򴰡�\n");
	call_out("teach5",7,ob);
}



void teach5(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ���˵һ˵����wear��remove��sleep���\n");	
	command("say wear��remove�ֱ��Ǵ������ѵ��·������õģ�sleep��˯�����\n");
	command("say ؤ����ӿ������˯�����������ɵ�Ҫ����Ϣ��֮��ĳ�������˯����\n");
	command("say ��֪����ϸһ��Ļ���������help��ѯ�Լ��Լ�ʵ����\n");	
}		
