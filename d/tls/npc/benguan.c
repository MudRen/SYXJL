inherit NPC;
#include "/quest/quest.h"

void create()
{
	set_name("本观", ({ "ben guan","guan"}) );
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	    );
        set("gender", "男性" );
	set("class", "bonze");
	set("age", 65);
	set("shen_type", 1);
	set("str", 32);
	set("int", 32);
	set("con", 32);
	set("dex", 32);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 800000);
	set("score", 100000);

	set_skill("force", 150);
	set_skill("kurong-changong", 150);
	set_skill("dodge", 150);
	set_skill("duanjia-shenfa", 150);
	set_skill("parry", 130);
	set_skill("finger", 160);
	set_skill("unarmed", 180);
	set_skill("yiyang-zhi", 160);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "duanjia-shenfa");
	map_skill("parry", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");
	
        create_family("天龙寺", 6, "弟子");
        set("chat_chance_combat", 40); 
        set("chat_msg_combat", ({
		(: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "yizhi" :),
            })   );
	setup();

}
