// huoji. 药铺伙计

//inherit NPC;
//inherit F_DEALER;
inherit F_VENDOR_SALE;
void create()
{
	reload("huoji");
	set_name("药铺伙计", ({ "huoji" }));
	set("shop_id",({"huoji"}));
        set("shop_title","药铺伙计");
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是平神医从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jinchuang",
		"/d/city/npc/obj/yangjing",
                "/d/city/obj/jiangcha",
                 "/clone/misc/dongshang",
                 "/clone/misc/fashao",
                 "/clone/misc/shanghan",
                 "/clone/misc/gaoyao",
                 "/clone/misc/keteling",
	}));

	setup();
       carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
              ::init();
              add_action("do_vendor_list", "list");
}
