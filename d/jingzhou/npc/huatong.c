// Npc: /huatong.c
// Date: 99/06/02 by Byt
#include <ansi.h>
inherit NPC;
int ask_send();

void create()
{
        set_name("��ͯ", ({ "hua tong","tong" }) );
        set("gender", "����" );
        set("age", 16);

        set("str", 22);
        set("int", 26);
        set("per", 23);
        set("kar", 25);
        set("con", 23);
        set("dex", 23);
        set("long",
	"һ������ɰ����ͻ�ͯ�ӡ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("env/wimpy", 30);

        set("inquiry", ([
            "�ͻ�" : (: ask_send :),
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
        if (ob->query_temp("tasked")==1) return ;
        if (ob->query_temp("task")==1) return ;   
        if (ob->query_temp("send")==1) return ;
	if (ob->query("class") =="bonze" ) return ;
	if (ob->query("class") =="taoist" ) return ;	
	command("say ��λ" +RANK_D->query_respect(ob)+ "����֦���͸���������˰ɣ�\n"NOR);
	add_action("do_send", "song");
}


int ask_send()
{
        command("say ������"HIR"(song)"NOR+CYN"����˭�أ�\n"NOR);
        return 1;
}

int do_send(string arg)
{
	object ob,me,where;

	if(!arg || arg=="") {
		command("say ������"HIR"(song)"NOR+CYN"����˭�أ�\n"NOR);
		return 1;
	}
	me=this_player();
	ob = find_player(arg);
	if( !ob ) ob = find_living(arg);
	if(arg=="hua tong")
	{
		message_vision(CYN"��ͯ��æ��$N�ڰ��֣�˵�������޹�����»����Ҳ̫�����ˡ���\n"NOR,me);
		return 1;
	}

	if (!ob) {
		command("say ����˺�����Ү������\n");
		return 1;
	}
	if(me->query_temp("flower")!=1)
	{
		command("say �����Ȱѻ����Ұɡ�\n");
		return 1;
	}
	where = environment(ob);
	if (!where) {
		command("? "+me->query("id"));
		command("say û������˰���\n");
		return 1;
	}
	if(me->query("gender")=="Ů��")
			message_vision(CYN"��ͯ��$NЦ��Ц��˵��������λ��������������ȥ�ˡ���\n"NOR,me);
	else 
			message_vision(CYN"��ͯ��$NЦ��Ц��˵��������λ�ֵܣ������������ȥ�ˡ���\n"NOR,me);
	ob->set_temp("send",1);
	this_object()->move(environment(ob));
	call_out("sended",2,me,ob);
	return 1;
}



int accept_object(object me, object ob)
{

        if((ob->query("id") == "bai ju")||(ob->query("id") == "hung ju")||(ob->query("id") == "zi ju")||(ob->query("id") == "lu ju"))
        {
                command("xixi "+me->query("id"));
		me->set_temp("flower",1);
		command("say ������"HIR"(song)"NOR+CYN"����˭�أ�\n"NOR);		

	}
	return 1;
}



void sended(object who,object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("hi "+ob->query("id"));	
	command("give flower to "+ob->query("id"));	
	command("say ��������"+who->query("name")+"("+who->query("id")+")���Ұ��������͸����������պ��ˡ�\n");							
	command("bow "+ob->query("id"));	
	who->delete_temp("send");
	who->delete_temp("flower");	
	ob->delete_temp("flower");		
	ob->delete_temp("send");	
	this_object()->move("/d/jingzhou/huadian");
}
