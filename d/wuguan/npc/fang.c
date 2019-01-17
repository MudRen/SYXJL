// Npc: /d/wuguan/npc/fang.c
// Date: 99/05/31 by Byt
#include <ansi.h>
inherit NPC;
int ask_literate();
void create()
{
	set_name("������", ({ "fang xiansheng", "fang" }));
	set("long", "��λ������Ͳ�����������ض��顣��\n");
	set("gender", "����");
	set("age", 65);

	set_skill("literate", 50);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400);
	set("shen_type", 1);

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
			command("say ��λС���������ѧЩ֪ʶ"HIR"(xue fang literate)"NOR+CYN"�ɡ�\n"NOR);
		else 
			command("say ��λС�ֵܣ�������ѧЩ֪ʶ"HIR"(xue fang literate)"NOR+CYN"�ɡ�\n"NOR);
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��"))
                return 0;
        ob->add_temp("mark/��", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/��"))
                who->set_temp("mark/��", 0);
        if (ob->query("money_id") && ob->value() >= 100) 
        {
                message_vision("������ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
                who->add_temp("mark/��", ob->value() / 50);
                return 1;
        }
}
