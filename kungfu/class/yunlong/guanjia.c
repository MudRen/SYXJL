// guanjia.c
#include "/quest/quest.h"
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("宋厄年", ({ "song enian","song" }) );
        set("title", "云龙门军师");
        set("gender", "男性" );
        set("age", 40);

        set("str", 22);
        set("int", 26);
        set("per", 23);
        set("kar", 25);
        set("con", 23);
        set("dex", 23);
        set("long",
"他看上去一副精明能干的模样，专门负责计划安排云龙门中各种大小事务。\n");
        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("env/wimpy", 30);

        set("max_neili", 1000);  
        set("neili", 1000);             
        set("jiali", 70);

	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("sword", 90);
	set_skill("whip", 70);
	set_skill("hand", 60);
	set_skill("claw", 60);
	set_skill("yunlong-shengong", 60);
	set_skill("yunlong-shenfa", 60);
	set_skill("yunlong-xinfa", 60);
	set_skill("yunlong-bian", 60);
	set_skill("yunlong-jian", 70);
	set_skill("yunlong-shou", 40);
	set_skill("yunlong-zhua", 40);

	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "yunlong-jian");
	map_skill("sword", "yunlong-jian");
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand", "yunlong-shou");
	prepare_skill("claw", "yunlong-zhua");
	create_family("云龙门",2, "弟子");
	set("class", "yunlong-xinfa");
      
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

        add_money("gold", 10);
}
