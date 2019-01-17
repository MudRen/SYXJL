inherit NPC;
int ask_jueji();
void create()
{
        set_name("����ʦ̫", ({
                "jingxian shitai",
                "jingxian",
                "shitai",
        }));

        set("long",
                "����һλ����ʦ̫��\n"
        );

        set("gender", "Ů��");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 70);
        set("combat_exp", 400000);
        set("score", 100);

        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("fuliu-jian", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("sword", "fuliu-jian");
        map_skill("parry", "fuliu-jian");
        prepare_skill("sword", "fuliu-jian");

        set("chat_chance",5);
        set("chat_msg", ({
               "����ʦ̫̾�˿�����\n",
               "����ʦ̫˵������ʱ�������ܼ̳��ҵ��𽣾���������\n", 
                        }) ); 
        set("inquiry",([
             "�𽣾���" : ( : ask_jueji : ),
              ]));
 
        create_family("������", 4, "����");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/changjian")->wield();
}

int ask_jueji()
{
	object me = this_player();

	if( (string)me->query("family/family_name") != "������" )    {
	      command("say ʩ���뱾������ԨԴ���������");
	      command("? "+(string)me->query("id"));
	      return 1; 
	}

	if( (int)me->query("sword") == 1 )	{
	      say("����ʦ̫��Щ��ŭ�ˡ�\n");
	      command("say ���Ѿ����̸����ˡ��㻹���ʸ�ʲô��");
	      return 1;
	}  
	else
	{
	      if((int)me->query_skill("fuliu-jian",1) < 80 )   {
	         command("say ��Ļط����������Ϊ̫���ˣ��޷�����ҵľ�������");
	         return 1; 
	        }         
	      else if((int)me->query_skill("linji-zhuang",1) < 80 )   {
	         command("say ����ټ�ʮ��ׯ����Ϊ̫���ˣ��޷�����ҵľ�������");
        	 return 1; 
	        }  
	      else 
	        {
        	 command("smile"); 
	         command("say ���Ҿͽ����𽣾����ɡ�\n");
	         me->set("sword",1);
	         return 1;
	        }  
	}    
}