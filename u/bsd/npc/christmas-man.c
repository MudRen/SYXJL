//christmas-man.c ʥ������
//by bsd 12/18/2000

#include <ansi.h>

 inherit NPC;
 int ask_me();

 void create()
 {
	set("title",HIC"��Ե���մ�ʹ"NOR);
        set("nickname",HIW"���"HIG"��"HIM"С��"NOR);
        set_name("ʥ������",({"Santa claus", "shengdan laoren", "laoren"}));
	set("gender","����");
        set("age",60);
	set("long",
	         "��������Ե�Ľ��մ�ʹ,ÿ�����˿��ֵĽ���,\n"
		 "���ͻ����صĳ�����,�����ܻ����Ҵ�Щ����\n"
		 "������,�����ĺͰ�����,һ��Ц�Ǻǵ�����,��\n"
		 "���鲻�Խ���������ӽ��ӽ�.\n");
	set("attitude","peaceful");
	set("str",40);
	set("int",40);
	set("con",40);
	set("dex",40);
	set("per",28);

	set("chat_chance",1);
	set("chat_msg",({
                HIY"ʥ������Ц�Ǻǵ�˵��: ʥ���ڵ���,��ҽ��տ��ְ�.\n"NOR,
		HIG"ʥ���������صĶ���˵,��֪����ʲô������? ask laoren about ���� \n"NOR
	}));


	set("inquiry",([
		"liwu" : (: ask_me :),
		"����" : (: ask_me :),
	]));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 500);
        set("max_jing", 500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("combat_exp", 8000000);
        set("score", 200000);

        set_skill("dodge", 500);                
        set_skill("shenxing-baibian", 500);
        set_skill("parry", 500);
	set_skill("unarmed",500);
	set_skill("force",500);
	set_skill("jiuyang-force",500);                
        
        map_skill("dodge", "shenxing-baibian");
	map_skill("unarmed","jiuyang-force");
	map_skill("force","jiuyang-force");

	setup();

	carry_object("/u/bsd/obj/silver-cloth")->wear();
}


int ask_me()
{
	object ob;
	ob = this_player();
	if(ob->query("shengdan") )
	{command ("shake");
	command ("say ��λ"+RANK_D->query_respect(ob)+"СС��;�̰�İ���С�����ϴ����ƨƨŶ�� ");
	return 1;
	}
        
/*	ob1 = new("/u/bsd/christmas/card");
	ob1->move(ob);
*/
	ob->set("shengdan",1);
  	ob->add("combat_exp",20000);
	ob->add("potential",10000);
        command("chat# ����" +ob->name(1)+ "˵������ף��ʥ���ڿ���,�ϼ��Ҹ�����");
        command("jh# ����" +ob->name(1)+ "˵������ף��ʥ���ڿ���,�ϼ��Ҹ�����");
	return 1;
}

