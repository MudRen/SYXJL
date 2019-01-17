// ma.c

#include <ansi.h>

inherit NPC;
int ask_me();

string ask_me(object who);

void create()
{
        set_name("����", ({ "ma jingzhong","ma" }) );
        set("title", "佻������ܹ�");
        set("gender", "����" );
        set("age", 56);

        set("str", 22);
        set("int", 26);
        set("per", 23);
        set("kar", 25);
        set("con", 23);
        set("dex", 23);
        set("long",
                
"���ճ������磬�������еĴ�С���񶼺���Ϥ��\n"
"�����е��¿�û���������ù�����\n");

        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("env/wimpy", 30);

        set("max_neili", 1000);  
        set("neili", 1000);             
	set("jiali", 70);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zhenjian" :),
                }) );
         set_skill("cuff", 100);
         set_skill("strike",100);
         set_skill("force", 100);
         set_skill("dodge", 100);
         set_skill("parry", 100);
         set_skill("sword", 100);
         set_skill("literate",100);
	 set_skill("unarmed",100);
         set_skill("huanhua-jian",100);
	 set_skill("tiexian-quan",100);
	 set_skill("guiyuan-dafa",100);
         set_skill("feihua-wuping",100);

	 map_skill("force","guiyuan-dafa");
	 map_skill("unarmed","tiexian-quan");
	 map_skill("sword","huanhua-jian");
	 map_skill("dodge","feihua-wuping");
	
	 set("chat_chance",30);
         set("chat_msg",({
         "��������������������ϵ��¡����ٺ�\n",
         "���մ�Ц����˭�ܹ����ù��ҵ��۾���\n",
        }));
      	set("inquiry", ([
	     "����" : (: ask_me :), 
	  ]));



      
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

        add_money("gold", 10);
}

void init()
{
	add_action("do_where", "where");
}

int do_where(string arg)
{
	object ob,me,where;
	mapping fam;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "佻�����")
		{command( "say �㲻�Ǳ��ɵ��ӣ��Ҳ��ܸ����㡣");return 1;}
		
	if(!arg || arg=="") {
		command("say ������˭��");
		return 1;
	}
	me=this_player();
	ob = find_player(arg);
	if( !ob ) ob = find_living(arg);
	if (!ob) {
		command("say ����û�����.");
		return 1;
	}
	where = environment(ob);
	if (!where) {
		command("say ����˲�֪��������Ү...");
		return 1;
	}
	printf(CYN"���������룬˵����%s(%s)������%s.\n"NOR,
		(string)ob->name(),
		(string)ob->query("id"),
		(string)where->query("short"));
	return 1;
}


int ask_me()
{
    object me,obj;
    me=this_player();
    obj=this_object();
    mapping fam;
    if (!(fam = this_player()->query("family")) || fam["family_name"] != "佻�����")
		{command( "say �㲻�Ǳ��ɵ��ӣ��Ҳ��ܷ���������");return 1;}

    command("sigh");
    command("say ��λ"+RANK_D->query_respect(me)+"����ү���źܾ��ˣ�Ҳ��֪��������ô���ˡ�");
    command("say ���ܲ��ܰ����ͷ��Ÿ����أ�");
    me->set_temp("send_letter",1);
           }
     return 1;
}
