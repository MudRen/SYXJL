// huoji. 药铺伙计

inherit NPC;
inherit F_DEALER;

string ask_me();
void create()
{
	set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是平神医从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/jinchuang",
                "/d/city/obj/jiangcha",
                 "/clone/misc/dongshang",
                 "/clone/misc/fashao",
                 "/clone/misc/shanghan",
                 "/clone/misc/gaoyao",
                 "/clone/misc/keteling",
		__DIR__"obj/yangjing"
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
add_action("do_buy", "buy");
        add_action("do_list", "list");
}
int accept_object(object who, object ob)
{
   if (ob->query("money_id") && ob->value() >= 100000)
        {
        tell_object(who, "伙计笑了笑，说道：平先生就在里面，请进去吧。\n");
      who->add_temp("liao",1);
        return 1;
       } 
       return 0;
}
