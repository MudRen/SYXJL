// Npc: /d/wuguan/npc/laoli.c
// Date: 99/05/31 by Byt

inherit NPC;
#include <ansi.h>

int ask_toy();
int ask_work();

void create()
{
        set_name("����", ({ "lao li", "li" }) );
        set("gender", "����" );
        set("age", 58);
        set("long", 
            "���Ǿ�����������Ʒ���ߵģ����Ƕ�ϰ�߳����������������ûʲô��֪���ˡ�\n");
        set("combat_exp", 10000);
        set("max_jing", 300);
        set("max_qi", 300);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 20);
        set("attitude", "friendly");
        set("inquiry", ([
            "����" : (: ask_toy :),
        ]) );

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
	if(!ob || environment(ob) != environment() ) return;
	if(this_player()->query_temp("jobed"))	
	{
		command("bow " + ob->query("id"));
		if(ob->query("gender")=="Ů��")
			command("say ��λС����������칤��"HIR"(ask li about ����)"NOR+CYN"�ɡ�\n"NOR);
		else 
			command("say ��λС�ֵܣ��������칤��"HIR"(ask li about ����)"NOR+CYN"�ɡ�\n"NOR);			
	}
}


int ask_toy()
{
 	object ob;
 	object me = this_player();
 	if(me->query_temp("toyed")==1) return 0;
        if(me->query_temp("job1")==1)
        {
        	command("say ��Ȼ���Ѿ����˻�Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ�\n");
        	ob = new("/d/wuguan/obj/chutou");
        	ob->move(this_player());
        	this_player()->set_temp("toyed",1);
		this_player()->delete_temp("jobed");        	
        	return 1;
        }
        else if(me->query_temp("job2")==1)
	{
		command("say ��Ȼ���Ѿ����˻�Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ�\n");
        	ob = new("/d/wuguan/obj/juzi");
        	ob->move(this_player());
        	this_player()->set_temp("toyed",1);
		this_player()->delete_temp("jobed");        	
        	return 1;
        }
        else if(me->query_temp("job3")==1)
	{
		command("say ��Ȼ���Ѿ����˻�Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ�\n");
        	ob = new("/d/wuguan/obj/chaidao");
        	ob->move(this_player());
        	this_player()->set_temp("toyed",1); 
		this_player()->delete_temp("jobed");        	   
        	return 1;
        }
         else if(me->query_temp("job4")==1)
	{
		command("say ��Ȼ���Ѿ����˻�Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ�\n");
        	ob = new("/d/wuguan/obj/piao");
        	ob->move(this_player());
        	this_player()->set_temp("toyed",1); 
		this_player()->delete_temp("jobed");        	       	
        	return 1;
        }
        else if(me->query_temp("job5")==1)
	{
		command("say ��Ȼ���Ѿ����˻�Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ�\n");
        	ob = new("/d/wuguan/obj/saozhou");
        	ob->move(this_player());
        	this_player()->set_temp("toyed",1); 
		this_player()->delete_temp("jobed");        	       	
        	return 1;
        }
}       


int accept_object(object who, object ob)
{
	object obj;
	obj=this_object();
//	if(! who->query_temp("worked") ) return 0;
	if(who->query_temp("task")!=1) return 0;
        if((ob->query("id") == "juzi")||(ob->query("id") == "piao")||(ob->query("id") == "chaidao")||(ob->query("id") == "saozhou")||(ob->query("id") == "chutou"))
        {
                command("nod");
                command("say ��ӭ�´�������\n");
		who->delete_temp("toyed");
		who->delete_temp("task");
		who->delete_temp("job1");
		who->delete_temp("job2");
		who->delete_temp("job3");
		who->delete_temp("job4");
		who->delete_temp("job5");										
		who->delete_temp("jobed");
		who->set_temp("tasked",1);
                who->delete_temp("toyed");
		remove_call_out("destrory");
		call_out("destrory",1,ob);
	}
	return 1;
}

   
void destrory(object ob)
{
        destruct(ob);
}
       
 

