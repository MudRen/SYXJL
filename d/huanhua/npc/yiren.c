#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("����", ({ "ren yi", "ren" }) );
	set("title","����");
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 35);
	set("str", 25);
	set("cor", 25);
	set("int", 25);
	set("long",
		"���Ǹ���������һ������������ﻹ����߶����ͦ��\n");
	set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4400);
        set("max_neili", 4400);
        set("jiali", 100);
        set("combat_exp", 3000000);
	set("attitude", "heroism");
	set("chat_chance_combat", 30);

	set("inquiry", ([
		"������"   : (: ask_me :),
		"�ڰ׽�"   : (: ask_me :),
	]) );

	
        set_skill("cuff", 185);
        set_skill("strike",185);
        set_skill("force", 190);
        set_skill("dodge", 190);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("literate",180);
	set_skill("unarmed",180);
        set_skill("huanhua-jian",200);
	 set_skill("tiexian-quan",180);
	 set_skill("guiyuan-dafa",180);
         set_skill("feihua-wuping",180);

	 map_skill("force","guiyuan-dafa");
	 map_skill("unarmed","tiexian-quan");
	 map_skill("sword","huanhua-jian");
	 map_skill("dodge","feihua-wuping");
     
        set("sword_count", 1);
        set("chat_chance", 50);
        set("chat_msg", ({
                "����˵��: ��֪��佻�Ϫ�� ! \n",
                "�����鲻�Խ���˵��佻�Ϫ���Ǹ������ĵط���\n",
                (: random_move :)
        }) );

	setup();
	
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
      
}

string ask_me(object who)
{
	object ob,me = this_player();
        if (query("sword_count") < 1){
        me->unconcious();
       return "�����BUG!!\n";}
	if (random(10) < 5) 
		return "�ҡ����������\n";
        message("vision", "����ͻȻһ�𣬿���...������֪�������Ķ��ˡ�\n" NOR,
		environment(), this_object() );
        say("�ܳ�ʱ��û��佻��ˣ������ȥ������\n");
                     
          ob = new ("/d/huanhua/obj/bsword");
	ob->move(this_player());
        add("sword_count", -1);
        me->start_busy(5);
	message_vision("�����˸�$Nһ�Ѻڽ���㱵��˾Ͳ�����\n",this_player());
        remove_call_out("destrory");
        call_out("destrory",1,this_object());
	return ("�鷳�����ѽ�����佻��ɡ�");
	
}
void destrory(object ob)
{
        destruct(ob);
}
