// Room: /d/wuguan/npc/chunzi.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("С����", ({ "xiao chunzi","chunzi"}) );
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
		command("say �ˣ������ʦѧ�������Ϊ��������ô����˵˵�ɡ�\n");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ����˵˵��ΰ�ʦ�ɡ�\n");	
	command("say apprentice(bai)�ǰ�ʦ���\n");			
	command("say ������Ѿ���ĳһ���ɵĵ��ӣ���ȥ���������ɣ��͵�����ʦ�ˡ�\n");	
	command("say ��ʦ�Ļ��������ܵ��������Լ��ܲҵķ������Ҫ��˼��\n");
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ������˵˵���ѧ�ա�\n");	
	command("say ��һ��������ʦ��ѧϰ�����learn(xue)����Ҫ��Ǳ�ܡ�\n");	
	command("say ����������Ķ��鼮�����study(du)����Ҫ�ҵ��鼮��\n");							
	command("say �������������������practice(lian)������ֻ�����������ա�\n");					
	command("say Ҫ�������ͱ����ȼ������գ����enable(jifa)��Ȼ��practice(lian)��\n");
	command("say �����ĺô������ܹ�����������������������֧�ֵ���߼������Ҳ���Ǳ�ܡ�\n");					
	command("say ����abadon(fangqi)�������������һЩ����С�ġ��������ļ��ܡ�\n");								
	command("say ��Ϊ��ѧ֮���ǣ����ھ����������ġ�\n");	
	call_out("teach3",7,ob);
}



void teach3(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ���̸һ̸���ڴ��������������exercise(dazuo)\n");	
	command("say ����Խ�ߣ��书��Ϊ��Խ�ߣ���ҿ���ͨ������������������\n");	
	command("say ���Ⱦ������ǣ������Ѿ������������ڹ�������Խ�ߣ����������޾�Խ������\n");							
	command("say ���ˣ���ֻ�Ǵ�ŵؽ���һ��ѧ�յ�ָ�\n");					
	command("say ��֪������ϸ�Ļ���������help��һ������˵�����Լ��Ժ��Լ���ʵ���ˡ�\n");							
}	
	
