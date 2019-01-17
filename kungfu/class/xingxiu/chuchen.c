// chuchen.c ������
// by QingP

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("������", ({ "chuchen zi", "chuchen" }));
	set("nickname", "�����ɰ�ʦ��");
	set("long", 
		"�����Ƕ�����İ˵��ӳ����ӡ�\n"
		"����İ��֣����ְ��������ſ���ȥ����Ϊ��ΰ��\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 15);
	set("combat_exp", 100000);
	set("score", 20000);

          set_skill("force", 60);
          set_skill("dodge", 50);
          set_skill("strike", 85);
          set_skill("claw", 75);
	  set_skill("poison", 50);
	  set_skill("throwing", 50);
          set_skill("staff", 90);
          set_skill("parry", 80);
	  set_skill("literate", 45);
	set_skill("beiming-zhenqi", 50);
	set_skill("zhaixinggong", 45);
	set_skill("xingchen-zhang", 65);
	set_skill("wugong-zhao", 60);
	set_skill("tianshan-zhang", 90);

	map_skill("force", "beiming-zhenqi");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingchen-zhang");
	map_skill("claw", "wugong-zhao");
	map_skill("parry", "xingchen-zhang");
	map_skill("staff", "tianshan-zhang");
	
	prepare_skill("strike", "xingchen-zhang");
	prepare_skill("claw", "wugong-zhao");

	create_family("������", 2, "����");

	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;
        mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "������") &&
                        (!wizardp(ob))) {
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
                }
        }
}

void do_killing(object ob)
{
	if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}

void attempt_apprentice(object ob)
{
	command("say ���ɻ�û��������ͽ�ء�");
}