inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("�峤", ({ "cun zhang", "zhang" }));
	set("long", "¹������Ҵ�峤��������������ӣ�\n");
	set("gender", "����");
	set("age", 50);

	set_skill("literate", 100);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
//	set("shen_type", 1);
	setup();

	set("chat_chance", 5);
	set("chat_msg", ({
		"�峤Ц���е�˵���������򷿵İɣ���������ķ���������⡣\n"
			}) );
}

void init()
{

}

int accept_object(object who, object ob)
{
    if (this_player()->query("age")<18) 
        {      write("��̫С����Щ���������򷿰ɣ�\n");
               return 0;
        } 
        if (!undefinedp(this_player()->query("myroom")))
        {     write("�峤�����˵�����Ѿ��������ѽ��\n");
              return 0;
        }
	if (ob->query("money_id") && ob->value() >= 10000000) {
		message_vision("�峤���˵Ķ�$N˵���ðɣ��뵽��Ҵ忴�������·��ɡ�\n", this_player());
	        this_player()->set("myroom/time",time());
		return 1;
	}

}
