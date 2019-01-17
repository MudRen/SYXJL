// Npc: /d/wuguan/npc/chuzi.c
// Date: 99/05/31 by Byt

inherit NPC;
#include <ansi.h>

int ask_food();
int ask_water();

void create()
{
        set_name("�ֳ���", ({ "pang chuzi", "chuzi" }) );
        set("gender", "����" );
        set("age", 58);
        set("long", 
            "���Ǿ�����ݵĳ��ӣ����ֵģ��غ���ʵ��\n");
        set("combat_exp", 10000);
        set("max_jing", 300);
        set("max_qi", 300);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 20);
        set("attitude", "friendly");
        set("inquiry", ([
            "ʳ��" : (: ask_food :),
            "food" : (: ask_food :),
            "ˮ"   : (: ask_water :),
            "water" : (: ask_water :),                                    
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
		command("bow " + ob->query("id"));
		if(ob->query("gender")=="Ů��")
			command("say ��λС��������ǳ�����������ȿ�����ʲô�Եĺͺȵģ����û���������\nҪʳ��"HIR"(ask chuzi about ʳ��)"NOR+CYN"�ͺȵ�"HIR"(ask chuzi about ˮ)"NOR+CYN"�ɡ�\n"NOR);
		else 
			command("say ��λС�ֵܣ������ǳ�����������ȿ�����ʲô�Եĺͺȵģ����û���������\nҪʳ��"HIR"(ask chuzi about ʳ��)"NOR+CYN"�ͺȵ�"HIR"(ask chuzi about ˮ)"NOR+CYN"�ɡ�\n"NOR);			
}


int ask_food()
{
 	object ob;
 	object me = this_player();
	switch( random(3) ) 
        	{
		case 0:
			ob = new("/d/wuguan/obj/baozi");
			ob->move(me);
			command("say ˭֪���вͣ����������࣡���˷��ˡ�\n");
        		message_vision("�ֳ��Ӹ�$Nһ�����ӡ�\n",me);			
			break;
		case 1:
			ob = new("/d/wuguan/obj/yuebing");
			ob->move(me);			
			command("say ˭֪���вͣ����������࣡���˷��ˡ�\n");		
        		message_vision("�ֳ��Ӹ�$Nһ���±���\n",me);							
			break;
		case 2:
			ob = new("/d/wuguan/obj/rice");
			ob->move(me);			
			command("say ˭֪���вͣ����������࣡���˷��ˡ�\n");
        		message_vision("�ֳ��Ӹ�$Nһ���׷���\n",me);									
			break;
		}
	return 1;
}	



int ask_water()
{
 	object ob;
 	object me = this_player();
	ob = new("/d/wuguan/obj/tea");
	ob->move(me);			
	command("say �Ɑ�����͸���ɣ��������Ӵ��\n");	
	message_vision("�ֳ��Ӹ�$Nһ������衣\n",me);				
	return 1;
}	

