// goudu.c

// shilling 97.2



inherit NPC;

//inherit F_MASTER;



#include <ansi.h>



string ask_me();



void create()

{

	set_name("����", ({ "gou du", "gou" }));

	set("long", 

		"������ȥҲ�Ǽ�ʮ������ˣ�ȴ�Ǵ�Ȼһ������ӵ�ģ����\n");

	set("gender", "����");

	set("age", 50);

	set("attitude", "friendly");

	set("shen_type", 1);

	set("str", 25);

	set("int", 35);

	set("con", 25);

	set("dex", 25);



	set("inquiry", ([

	  "����":(:ask_me:),

	]) );

	

	set("max_qi", 800);

	set("max_jing", 800);

	set("neili", 800);

	set("max_neili", 800);

	set("jiali", 60);

	set("combat_exp", 150000);

	set("score", 40000);



    set_skill("blade",60);

    set_skill("ruyi-dao",60);

	set_skill("force", 60);

	set_skill("dodge", 60);

	set_skill("unarmed", 60);

	set_skill("parry", 60);

          set_skill("lingbo-weibu", 60);
    set_skill("beiming-shengong",60);

	set_skill("zhemei-shou", 60);



	map_skill("unarmed", "zhemei-shou");

          map_skill("dodge", "lingbo-weibu");
	map_skill("force", "beiming-shengong");

	map_skill("blade", "ruyi-dao");



	set("book_count", 1);



	create_family("��ң��", 3, "����");

	set("title","��ң�ɡ����Ȱ��ѡ�");

	set("nickname","���");

	setup();

	carry_object("/d/xiaoyao/obj/cloth")->wear();

//	carry_object(__DIR__"obj/blade")->wield();



}





string ask_me()

{

        mapping fam; 
 object ob,me;



          if (!(fam = this_player()->query("family")) || fam["family_name"] != "��ң��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
 
 me=this_player();

	if (query("book_count") < 1)

		return "�������ˣ��Ǳ���������Ѿ����͸������ˡ�";   

	add("book_count", -1);                  

	command("say �������������û���ˣ����������ɸ��ִ����ֵ�������");

	command("say ��Ȼ����ô��ѧ���ҾͰ����͸���ɡ�\n");

      ob = new("/d/shaolin/obj/book-paper");

  ob->move(this_player());



	return "�Ȿ���ǧ��Ҫ������˰�������һ��Ͳ������ˡ�\n";

}

