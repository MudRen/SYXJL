// ping.c ƽһָ

inherit NPC;
inherit F_DEALER;

string ask_liao();
void create()
{
	set_name("ƽһָ", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "ҩ���ϰ�");
	set("gender", "����");
	set("long", "������ҽ���߳��ġ�ɱ����ҽ��ƽһָ���������Ը�Ź֣�����ʲô�˶�ҽ�ġ�\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);

        set("inquiry", ([
              "����" : (: ask_liao :),
        ]));
	set("vendor_goods", ({
	}));
         //set("no_get,1);
	setup();
     this_player()->add_money("gold", 1);
     this_player()->carry_object("/clone/misc/cloth")->wear();
}

string ask_liao()
{
       object ob;
        ob=this_player();
      if(ob->query_temp("liao")<1) 
      {
        return "����ȸ�Ǯ��!";
      }
      if ((int)this_player()->query("eff_qi") >= (int)this_player()->query("max_qi")) 
        return RANK_D->query_respect(this_player()) + "��Ѫ���㣬����ҽ�ΰ���";
       ob->set("eff_jing", (int)ob->query("max_jing"));
       ob->set("jing", (int)ob->query("max_jing"));
       ob->set("eff_qi", (int)ob->query("max_qi"));
       ob->set("qi", (int)ob->query("max_qi"));
       ob->delete_temp("liao");
       write("ƽһָ�����κ����ˣ�����û���ů����ģ�����ʧȥ����Ѫ���ص������� \n");
       return "������������ˣ���һ����"; 
}
void init()
{
//add_action("do_buy", "buy");
}
