// shihou.c ʨ����
// by QingP
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("ʨ����", ({ "shihou zi", "shihou" }));
	set("nickname", "�����ɶ�ʦ��");
	set("long", 
		"�����Ƕ�����Ķ�����ʨ���ӡ�\n"
		"����ʮ������ͣ�˫���ϸ�����һֻ���λεĻƽ�󻷣�ʨ�����ڣ�\n"
		"��ò��Ϊ�׺ݹ��죬��Ȼ����������ʿ��\n");
	set("gender", "����");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 1100);
	set("max_neili", 1100);
	set("jiali", 30);
	set("combat_exp", 200000);
	set("score", 30000);

          set_skill("force", 95);
          set_skill("dodge", 80);
          set_skill("strike", 85);
          set_skill("claw", 80);
	  set_skill("poison", 90);
	  set_skill("throwing", 60);
          set_skill("staff", 70);
          set_skill("parry", 90);
	  set_skill("literate", 85);
	set_skill("beiming-zhenqi", 85);
	set_skill("zhaixinggong", 75);
	set_skill("xingchen-zhang", 110);
	set_skill("wugong-zhao", 100);
	set_skill("tianshan-zhang", 50);

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
	carry_object("/clone/misc/cloth")->wear();
}

     void init()
{
        object ob;

        ::init();

        ob = this_player();
               if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="shihou zi")
        {
                      command("chat "+ob->query("name")+"!װʲô������ʿ�����ҹ��������ɡ�\n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","������" + RED + "��ͽ" NOR);   
        }

}      
void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}
