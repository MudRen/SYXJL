// Npc: /kungfu/class/shaolin/xuan-nan.c

// Date: YZC 96/01/19



inherit NPC;

inherit F_MASTER;



string ask_me();



void create()

{

	set_name("���Ѵ�ʦ", ({

		"xuannan dashi",

		"xuannan",

		"dashi",

	}));

	set("long",

		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�����ļ��ݣ�\n"

		"���ָ���צһ������˫Ŀ΢�գ�һ��û����ɵ�ģ����\n"

	);





	set("nickname", "����������");

	set("gender", "����");

	set("attitude", "friendly");

	set("class", "bonze");



	set("age", 70);

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



	set("combat_exp", 800000);

	set("score", 800000);



// before the modification, all the skills are 120

	set_skill("force", 120);

	set_skill("hunyuan-yiqi", 120);

	set_skill("dodge", 120);

	set_skill("shaolin-shenfa", 120);

	set_skill("parry", 120);

	set_skill("cuff", 120);

	set_skill("staff", 120);

	set_skill("finger", 190);

	set_skill("strike", 180);

	set_skill("jingang-quan", 120);

	set_skill("wuchang-zhang", 120);

	set_skill("yizhi-chan", 190);

	set_skill("banruo-zhang", 180);

	set_skill("buddhism", 130);

	set_skill("literate", 120);



	map_skill("force", "hunyuan-yiqi");

	map_skill("dodge", "shaolin-shenfa");

	map_skill("cuff", "jingang-quan");

	map_skill("finger", "yizhi-chan");

	map_skill("strike", "banruo-zhang");

	map_skill("staff", "wuchang-zhang");

	map_skill("parry", "wuchang-zhang");



	prepare_skill("finger", "yizhi-chan");

	prepare_skill("strike", "banruo-zhang");



	create_family("������", 36, "����");



	set("inquiry", ([

		"ʮ���޺���"       : (: ask_me :),

		"�޺�����"	   : (: ask_me :)

	]));



	set("chat_chance_combat", 45);

	set("chat_msg_combat", ({

		(: exert_function, "roar" :),

		(: exert_function, "recover" :),

	}) );

            set("no_get",1);

	setup();



	carry_object("/d/shaolin/obj/chanzhang")->wield();

	carry_object("/d/shaolin/obj/xuan-cloth")->wear();

}





#include "/kungfu/class/shaolin/xuan-nan.h"

