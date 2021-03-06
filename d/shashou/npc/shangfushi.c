// sgangfyshi.c 赏罚使

#include <ansi.h>
#include "/quest/quest.h"
inherit F_UNIQUE;
inherit NPC;

int ask_me();

void create()
{
       seteuid(getuid());
	set_name("黑白子", ({ "heibai zi", "zi" }) );
         set("nickname", HIM "冷面" NOR);
	set("gender", "男性");
	set("age", 48);
	set("long",
		"只见他昂然而立，青袍短须，容貌清癯，\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
	set("max_jing", 300);
	set("jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("strike",60);
	set_skill("wuji-shengong",60);
	set_skill("fanyun-zhang",60);
	set_skill("bugui-bufa",60);

	
	map_skill("force", "wuji-shengong");
	map_skill("dodge", "bugui-bufa");
	map_skill("parry", "fanyun-zhang");
	map_skill("strike", "fanyun-zhang");

	
	create_family("杀手楼", 2, "杀手");
	set("title","杀手楼赏罚使");

            set("no_get",1);
	set("inquiry", ([
                "职位" : (: ask_me :),
	]));

	setup();

}

int ask_me()
{
        object me;
	mapping fam;
	me=this_player();
        fam = me->query("family");

	if ( ((string)me->query("family/family_name") == "" ) || 
		( (string)me->query("family/family_name") != "" &&
		(string)me->query("family/family_name") != "杀手楼" ) )
	{
		message_vision("黑白子对$N说道：你不是本帮的人，帮内事务怎能告诉你？\n", me);
		return 1;
	}

	if ( (int)me->query("combat_exp") < 100000 )
	{
		message_vision("黑白子对$N说道：你对本帮的贡献还不够，以后再说吧。\n", me);
		return 1;
	}
	message_vision("黑白子对$N说道：你对本帮的贡献不小，先在就提升你做本帮的护法吧。\n", me);
	if ( (int)me->query("combat_exp") >= 500000 )
	{
                me->set("title", "杀手楼红衣杀手");
		return 1;
	}
	if ( (int)me->query("combat_exp") >= 400000 )
	{
               me->set("title","杀手楼青衣杀手");
		return 1;
	}
	if ( (int)me->query("combat_exp") >= 300000 )
	{
                me->set("title","杀手楼黄衣杀手");
		return 1;
	}
	if ( (int)me->query("combat_exp") >= 200000 )
	{
                me->set("title","杀手楼蓝衣杀手");
		return 1;
	}
	if ( (int)me->query("combat_exp") >= 100000 )
	{
                me->set("title","杀手楼白衣杀手");
		return 1;
	}
	return 1;
}

