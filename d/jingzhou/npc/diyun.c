// Room: /d/jingzhou/npc/diyun.c
// Date: 99/06/01 by Byt

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "di yun", "di" }));
        set("gender", "����");
        set("age", 23);
        set("str", 40);
        set("dex", 20);
        set("long", "ֻ����������ڣ�ȧ��΢�ߣ����ִ�ţ������������³�����ׯ�����꺺�ӡ�\n");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 15);

        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}



int accept_object(object who, object ob)
{
	object obj,ob1;
	obj=this_object();
	if(who->query_temp("task")!=1) return 0;
        if((ob->query("id") == "tangshi xuanzhu"))
        {
                command("sish");
		remove_call_out("destrory");
		call_out("destrory",1,ob);
		ob1 = new("/d/jingzhou/obj/jianpu");
		ob1->move(who);
		ob1 = new("/d/jingzhou/obj/wucanyi");
		ob1->move(who);
	}
	return 1;
}

   
void destrory(object ob)
{
        destruct(ob);
}
       
 


