// tianlang.c ������
// by QingP
#include <ansi.h>

inherit NPC;
#include "/quest/quest.h"
string ask_me();

void create()
{
	set_name("������", ({ "tianlang zi", "tianlang" }));
	set("nickname", "��������ʦ��");
	set("long", 
		"�����Ƕ�����������������ӡ�\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 150000);
	set("score", 30000);

          set_skill("force", 75);
          set_skill("dodge", 75);
          set_skill("strike", 75);
          set_skill("claw", 75);
	  set_skill("poison", 80);
	  set_skill("throwing", 55);
          set_skill("staff", 70);
          set_skill("parry", 70);
	  set_skill("literate", 70);
	set_skill("beiming-zhenqi", 70);
	set_skill("zhaixinggong", 70);
	set_skill("xingchen-zhang", 70);
	set_skill("wugong-zhao", 70);
	set_skill("tianshan-zhang", 75);

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
/*
     void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("shen")>=0&&ob->query("family/master_id")=="tianlang zi")
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
*/
