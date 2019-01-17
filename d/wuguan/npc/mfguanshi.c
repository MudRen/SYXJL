// Npc: /d/wuguan/npc/mfguanshi.c
// Date: 99/05/31 by Byt

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("������", ({ "mafang guanshi", "guanshi" }) );
        set("gender", "����" );
        set("age", 38);
        set("long", 
            "����������ݵ�һ��С�ܼң�ר�������С���£�\n");
        set("combat_exp", 10000);
        set("max_jing", 300);
        set("max_qi", 300);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 20);
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
	if(!ob || environment(ob) != environment() ) return;
	if(this_player()->query_temp("job5")==1)	
	{
		command("pat " + ob->query("id"));
		if(ob->query("gender")=="Ů��")
			command("say ��λС�����������ɨ"HIR"(sao ��)"NOR+CYN"�ɡ�\n"NOR);
		else 
			command("say ��λС�ֵܣ���������ɨ"HIR"(sao ��)"NOR+CYN"�ɡ�\n"NOR);			
	}
}
