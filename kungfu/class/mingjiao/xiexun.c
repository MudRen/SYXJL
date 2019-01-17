// XieXun.c

// pal 1997.05.09



#include "ansi.h"



inherit NPC;

inherit F_MASTER;

inherit F_UNIQUE;



void create()

{

    set_name("лѷ", ({"xie xun", "xie", "xun", }));

	set("long",

        "����һλ��Ŀ�ΰ�쳣�ĵ����ߣ���һ���ײ����ۡ�\n"

        "����ͷ�Ʒ����������ݣ���������һ�㣬ֻ����ֻ�۾�����������\n"

	);



	set("title",HIG "����" HIY "��ëʨ��" NOR);

	set("level",9);

	set("gender", "����");

	set("attitude", "peaceful");



	set("age", 63);

	set("shen_type", 1);

	set("str", 30);

	set("int", 30);

	set("con", 30);

	set("dex", 30);



	set("max_qi", 3500);

	set("max_jing", 1500);

	set("neili", 3000);

	set("max_neili", 3000);

	set("jiali", 150);



	set("combat_exp", 900000);

	set("score", 800000);



    	set_skill("force", 160);

	set_skill("dodge", 140);

	set_skill("parry", 140);

	set_skill("cuff", 200);

//    	set_skill("staff", 180);

	set_skill("hunyuan-yiqi", 160);

	set_skill("shaolin-shenfa", 140);

    	set_skill("qishang-quan", 200);

    	set_skill("jingang-quan", 150);

    	set_skill("literate", 100);



	map_skill("force", "hunyuan-yiqi");

	map_skill("dodge", "shaolin-shenfa");

	map_skill("cuff", "qishang-quan");

    	map_skill("parry", "jingang-quan");



	prepare_skill("cuff","qishang-quan");



	set("chat_chance_combat", 200);

	set("chat_msg_combat", ({

		(: command("perform hunpofeiyang") :),

	}) );



	setup();



    	carry_object("/d/mingjiao/obj/baipao")->wear();

}



void init()

{

	object me,ob;

	me = this_object () ;

	ob = this_player () ;



	::init();



	if( interactive(ob) && !is_fighting() )

	{

		remove_call_out("greeting");

		call_out("greeting", 1, me, ob);

	}

}



#include "fawang.h"

