// Npc: /d/wuguan/npc/zhangfeng.c
// Date: 99/05/31 by Byt

inherit NPC;
#include <ansi.h>

int ask_toy();
int ask_work();
void create()
{
        set_name("�ŷ�", ({ "zhang feng", "zhang" }) );
        set("gender", "����" );
        set("age", 28);
        set("long", 
            "������ò�Ͱ���Ц�Ǻǵģ�һ���ø����̴���\n");
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
            "����" : (: ask_work :),
            "job"  : (: ask_work :), 
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
        if (ob->query("biye")==1) return ;                
	if(!this_player()->query_temp("jobed"))	
	{
		command("bow " + ob->query("id"));
		if(ob->query("gender")=="Ů��")
			command("say ��λС���������ȱ���֣�����������칤��"HIR"(ask zhang about job)"NOR+CYN"������\n"NOR);
		else 
			command("say ��λС�ֵܣ�������ȱ���֣�����������칤��"HIR"(ask zhang about job)"NOR+CYN"������\n"NOR);			
	}
}



int ask_toy()
{
        command("say ��ȥ��Ʒ��������Ҫ�ɣ�\n");
        return 1;
}

int ask_work()
{
	object ob = this_player();
        if (ob->query("combat_exp") >= 10000)
        {
             command("say �㹦���Ѿ��㹻��������������û��ʲô�ʺ���Ĺ����ˡ�\n");	
             ob->set("biye",1);
             return 1;
        }
             
        if(!ob->query_temp("jobed"))
        {
        	switch( random(5) ) 
        	{
		case 0:
			ob->set_temp("job1",1);
			ob->set_temp("jobed",1);			
			command("say ���������кö���Ҫ��������ȥ����Ʒ���칤�ߣ�Ȼ��ȥ��Ժ���ݰɡ�\n");
			break;
		case 1:
			ob->set_temp("job2",1);
			ob->set_temp("jobed",1);						
			command("say ���������кö���Ҫ��������ȥ����Ʒ���칤�ߣ�Ȼ��ȥ��Ժ��ľͷ�ɡ�\n");
			break;
		case 2:
			ob->set_temp("job3",1);
			ob->set_temp("jobed",1);						
			command("say ���������кö���Ҫ��������ȥ����Ʒ���칤�ߣ�Ȼ��ȥ��Ժ����ɡ�\n");
			break;
		case 3:
			ob->set_temp("job4",1);
			ob->set_temp("jobed",1);						
			command("say ���������кö���Ҫ��������ȥ����Ʒ���칤�ߣ�Ȼ��ȥ��Ժ���˵ذɡ�\n");
			break;
		case 4:
			ob->set_temp("job5",1);
			ob->set_temp("jobed",1);						
			command("say ���������кö���Ҫ��������ȥ����Ʒ���칤�ߣ�Ȼ��ȥ��Ժɨ���ɡ�\n");
			break;
	      	}
        }
        else
        	command("say �㲻���Ѿ����˹����𣿻�����ȥ����\n");
        	
       	return 1;
}

