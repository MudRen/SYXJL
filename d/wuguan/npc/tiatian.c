// Room: /d/wuguan/npc/tiatian.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("Ѱ��", ({ "xun hua","xun"}) );
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
		command("say �����𣿻�ӭ����������������һЩ�򵥵Ľ�̸���ɡ�\n");
       	        command("tell " + ob->query("id") + " HI!WELCOME!");
		call_out("teach1",5,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ���ȣ�Ҫ֪��������ʲô������ߣ�������who�����顣\n");	
	command("say ֻҪ����who����Ϳ��Բ�ѯ����������ҵ��������֡�\n");			
	command("say ֻҪ����who -i����Ϳ��Բ�ѯ����������ҵ�Ӣ�����֡�\n");	
	command("say ֻҪ����who -l����Ϳ��Բ�ѯ����������ҵ���Ӣ�����֡�\n");
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say �����ڿ��������һ��������ҵ�Ӣ�����֡���tell����������̸��\n");	
	command("say �����ǣ�tell <���Ӣ����> [��̸����]��\n");	
	command("say ���������һش���Ļ���֮���̸���Ϳ�����reply ���\n");							
	command("say �����ǣ�reply [�ش�����]��\n");					
	command("say reply  ���������ڻش��õģ������ڲ���ÿ�ζ�Ҫ����Է������֡�\n");							
	call_out("teach3",7,ob);
}



void teach3(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ������������ҵ�����̸�ķ������ô���������û��������\n");	
	command("say ����say������chat���\n");	
	command("say say��������ͬһ�����������˶�������˵���������ǣ�say [����]��\n");							
	command("say �����ǣ�reply [�ش�����]��\n");					
	command("say chat��������������Ϸ�е���Ҷ����������˵����������say���ơ�\n");							
	call_out("teach4",7,ob);
}	




void teach4(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say who,tell,say,reply ���������help����ѯ�������ǣ�help <������>��\n");	
	command("say ���������˽⣬������һ�£�Ȼ��������(east)�ߡ�\n");	
}	
