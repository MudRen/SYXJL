// zhou.c �ܲ�ͨ 
//Ronger 10/98
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int do_jiebai();
int do_back(object me);
void create()
{
	set_name("�ܲ�ͨ",({ "zhou botong","zhou","botong" }) );
	set("nickname",HIY"����ͯ"NOR);
	set("gender", "����" );
	set("age", 83);
	set("long", 
		"�������˳�����ͯ���ܲ�ͨ����Ȼ��ͷ�׷���������Ȼ������ӣ�\n"+
		"����Ц�����ģ�һ˫�۾������㲻ͣ�ع�µµ��ת��\n");
	set("inquiry", ([
		"����" : "�������ҵĺ��ֵܣ�ֻ�Ǻܾ�û�����ˡ�\n",
		"���" : (: do_jiebai :),
	]));

	set("str", 30);
	set("dex", 30);
	set("con", 25);
	set("int", 20);
	set("combat_exp", 1800000);
	set("attitude", "friendly");
	set("score", 400000);
	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 8500);
	set("max_neili", 8500);
	set("jiali", 100);

	set_skill("force", 200);
	set_skill("xiantian-gong", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("quanzhen-shenfa", 200);
	set_skill("parry", 200);
	set_skill("kongming-quan",200);
	set_skill("hubo", 300);
	set_skill("sword",200);
	map_skill("unarmed", "kongming-quan");
	map_skill("parry", "kongming-quan");
	map_skill("force", "xiantian-gong");
	map_skill("dodge", "quanzhen-shenfa");

	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
		(: command("say ������ԩ�޳𣬺α����?\n") :),
		(: command("sigh") :),
		(: command("hubo") :),
		(: command("sigh") :),
		(: command("hubo") :),
		(: command("yun regenerate") :),
		(: command("hubo") :),
		(: command("yun recover") :),
		(: command("hubo") :),
		}) );

          create_family("ȫ���", 3, "����");
	setup();
	carry_object("d/taohua/obj/cloth")->wear();
}
int do_jiebai()
{
	object ob;
	ob=this_player();
	if(ob->query("gender")!="����")
	{
		say("�ܲ�ͨ˵������������ͯ��ƽ������Ů�ˣ�ȥ��ȥ��ȥ���������ҡ���\n");
		return 1;
	}
	if((string)ob->query("zhou/canlearn") =="1")
	{
		say("�ܲ�ͨ˵���������ǲ����Ѿ�������𣿡�\n");
		return 1;
	}
              if(ob->query("int")> 25)
	{
	say("�ܲ�ͨ˵����������һ�����������ӣ������ֵܹ���������һ������\n"
	    "�ܲ�ͨҡ��ҡͷ��˵���������ȥ�ɡ���\n");
	return 1;
	}
	else
	say("�ܲ�ͨ���˵�����"+ob->query("name")+"����˵�����������Ժ���Ǻ��ֵܡ���\n");
	command("tell "+ob->query("id")+" �������һ�׿���ȭ��һ��˫�ֻ����Ĺ��򣬿��Խ��㡣\n"); 
	this_player()->set("zhou/canlearn", "1");
	return 1;
}
int recognize_apprentice(object ob)
{
	if ((string)ob->query("zhou/canlearn") != "1")
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
//		command("tell "+ob->query("id")+" ��ΪʲôҪ���㹦���أ�\n"); 
		return 0;
	}

	return 1;
}
int accept_object(object who, object ob)
{
	object me;
	me=this_object();
	if((string)ob->query("name") == "����")
        {
        call_out("destrory",1,me);
        message_vision("$N�ͳ�һ�����ߣ����ܲ�ͨ��ǰ���˻Σ��ܲ�ͨ�ŵ���æ�������ܣ�һ����һ��\n"
	"���ţ����ۣ��ߣ��ߣ�ҧ����������ֻ������Խ��ԽԶ��Խ��ԽС���ղ����š�\n",who);        
	return 1;
        }
}

void destrory(object ob)
{
        destruct(ob);
}

