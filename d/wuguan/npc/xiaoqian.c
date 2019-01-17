// Room: /d/wuguan/npc/xiaoqian.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("�����", ({ "ding qiubai","xiaoqian","ding"}) );
	set("gender", "����" );
	set("age", 25);
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
		command("say �������ٲ��˴��ɱɱ�ģ�û���˴�ɱ���Ͳ��������ˡ�\n");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ���֮��Ļ�ɱ��֮ΪPK(Player Killer)�����ڽ������ս���ɡ�\n");	
	command("say ս���ֱ����������fight��hit��kill��\n");			
	command("say fight�ǵ㵽��ֹ���д����գ���ʱ�ᱻ�Է��ܾ���\n");	
	command("say hit��ǿ����Է����У��ƶԷ�����򶷣��п��ܵ���������\n");
	command("say kill����ɱ���Է�����NPCʹ�õĻ���NPCҲ����ͼɱ���㡣\n");			
	command("say ���������������help�õ�����ϸ����Ϣ��Ҳ�����Լ����һ�¡�\n");	
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ������Լ�����ʱ����ɱ�����Ļ�������enforce(jiali)��prepare(bei)��\n");	
	command("say enforce(jiali)�Ǽ���������ÿ�λ��е���ʱ�����������˵С�\n");	
	command("say prepare(bei)�����ȭ�����ܣ�����ͬһʱ��ʹ������ȭ����\n");							
	command("say ������������ȭ�����Ի�����ϡ�\n");					
	command("say ���У���������б����Ļ�����������ȻҪ�ȿ���������\n");
	call_out("teach3",7,ob);
}



void teach3(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ��ֻ�Ǽ򵥵ؽ���һ��ս����ָ�����Ļ�������ȥ���һ�°ɡ�\n");	
	command("say �����ն�һ��С�Ĵ��£��м��мǡ�\n");	
	command("bye " + ob->query("id"));
}	
	
