

#include <ansi.h>



inherit NPC;



int do_eat();

int do_drink();

int do_say();

int do_tell();

int do_chat();

int do_emote();

int do_dazuo();

int do_tuna();

int do_study();

int do_lian();

int do_yun();

int do_cha();

int do_learn();

int do_teach();

int do_perform();

int do_vote();



void create()

{

	set_name("������", ({ "wan wutian", "wan", "wutian" }));

	set("title", HIC "���Ŀ���" NOR);

	set("nickname", HIY "��˼����" NOR);

	set("gender", "����");

	set("age", 24);

	set("long", "ûʲô�ɿ��ģ�һ����ͨ�˰��ˡ�\n");

	set("shen_type", 1);

	set("attitude", "peaceful");

	set("chat_chance", 5);

	set("chat_msg", ({

		"��������������˵�������ȥô����tender���ʺ��ˡ���\n",

		"������Ǻ�Ц��Ц��˵�������������ﶼ��ԭ��ģ�����ô������\n",

	}) );

	setup();

	carry_object("d/city/obj/cloth")->wear();

}



void init()

{

	object ob = this_player();

	::init();

	ob->set("startroom", "/u/tender/workroom");



	if(wizardp(ob)) return;

	add_action("do_eat", "eat");

	add_action("do_drink", "drink");

	add_action("do_say", "say");

	add_action("do_tell", "tell");

	add_action("do_tell", "reply");

	add_action("do_tell", "ce");

	add_action("do_chat", "chat");

	add_action("do_chat", "rumor");

	add_action("do_chat", "music");

	add_action("do_emote", "emote");

	add_action("do_emote", "chat*");

	add_action("do_emote", "rumor*");

	add_action("do_emote", "music*");

	add_action("do_dazuo", "dazuo");

	add_action("do_dazuo", "exercise");

	add_action("do_tuna", "tuna");

	add_action("do_tuna", "respirate");

	add_action("do_study", "study");

	add_action("do_study", "du");

	add_action("do_lian", "lian");

	add_action("do_lian", "practice");

	add_action("do_yun", "exert");

	add_action("do_yun", "yun");

	add_action("do_yun", "nixing");

	add_action("do_cha", "cha");

	add_action("do_cha", "check");

	add_action("do_learn", "learn");

	add_action("do_learn", "xue");

	add_action("do_teach", "teach");

	add_action("do_teach", "jiao");

	add_action("do_perform", "perform");

	add_action("do_vote", "vote");

}



int do_eat()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N���˿�$n��˵�����Ǻǣ����ﲻ׼������ʳ����\n", me, ob );



	return 1;

}



int do_drink()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$nһЦ��˵�����Ǻǣ������ֹ��ơ���\n", me, ob );



	return 1;

}



int do_say()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$n̾�˿���������ʲôҲ����˵�ˣ��ú÷�ʡ�ɡ���\n", me, ob );



	return 1;

}



int do_tell()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$n�ٺ�һ�֣�˵�������ͬ��ͨ�籨�Ű�����\n", me, ob );



	return 1;

}



int do_chat()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$nҡ��ҡͷ��˵����������ô��Ҳ��û���õ��ˡ���\n", me, ob );



	return 1;

}



int do_emote()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N����$nЦ�ˣ����Ǻǣ������ȥ���ٱ���ḻ�ɡ���\n", me, ob );



	return 1;

}



int do_dazuo()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$nһ�ֵ������Ǻǣ�������ʡ�������ɡ���\n", me, ob );



	return 1;

}



int do_tuna()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$nգ��գ�ۣ����Ǻǣ�������ʡ�㾫���ɡ���\n", me, ob );



	return 1;

}



int do_study()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$nҡ��ҡͷ��˵������Ҫѧ�Ķ����������ϡ���\n", me, ob );



	return 1;

}



int do_lian()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$n̾�˿�������������Ҫ�����㻹����Ϣ��Ϣ�ɡ���\n", me, ob );



	return 1;

}



int do_yun()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N����$n������Ц���������ڹ�׿Խ������֪���ˡ���\n", me, ob );



	return 1;

}



int do_cha()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$n����һ����˵��������ʵ�ڹ��������ʲô����\n", me, ob );



	return 1;

}



int do_learn()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N������$n��˵������ѧֵ�ñ��ã��������ڲ��ɡ���\n", me, ob );



	return 1;

}



int do_teach()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$nЦ��Ц��˵������̱���Ҳѧ��������\n", me, ob );



	return 1;

}



int do_perform()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N����$nЦ�ˣ����Ǻǣ����ղ�������Ҳ֪���ˡ���\n", me, ob );



	return 1;

}



int do_vote()

{

	object me = this_object();

	object ob = this_player();



	message_vision( "$N��$nЦ��Ц��˵������������������������������\n", me, ob );



	return 1;

}

