// Room: /d/wuguan/npc/brave.c
// Date: 99/05/30 by Byt

inherit NPC;

void create()
{
	set_name("�¸ҵ���", ({ "yonggan dexin","yonggan","brave"}) );
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
		command("say ����Ϸ��һƬ�ܴ�ĵ���������Ҫ���������ķ���\n");
		call_out("teach1",3,ob);
	}
}


void teach1(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say ��ÿ��һ��������ʱ�򣬶��ῴ�����ơ�����ĳ����� north �� west������\n");	
	command("say ��������������뱱�ߡ����������north��n�����ߣ���Ϊn��north�ļ򻯡�\n");			
	call_out("teach2",7,ob);	
}		


void teach2(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say �����Ǹ�����ļ򻯣�\n");	
	command("say north==n��south==s��west==w��east==e��\n");	
	command("say northwest==nw��        northeast==ne��\n");							
	command("say southwest==sw��        southeast==se��\n");					
	command("say southup==su��northup==nu��eastup==eu��westup==wu��\n");				
	command("say southdown==sd��        northdown==nd��\n");					
	command("say westdown==wd��         eastdown==ed��\n");										
	command("say ����һЩ����ĳ��ڣ��ڴ˲������ܡ�\n");										
	command("whisper " + ob->query("id") + " ��������(southwest)�ߣ��Ǳ���ר�˽������������̸���ġ�\n");												
}

