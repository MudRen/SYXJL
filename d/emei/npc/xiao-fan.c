// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("С��", ({ "xiao fan", "seller", "fan" }) );
	set("gender", "Ů��" );
	set("age", 32);
	set("long",
		"���Ǹ�С������һ��Ϊ�����ƶ������Ͷ�����ʵ�ͽ������¸��ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 250); 
        set("max_qi",300);
        set("qi",300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		__DIR__"obj/hulu",
		__DIR__"obj/doufu",
		__DIR__"obj/mantou",
		__DIR__"obj/tiejia",
                __DIR__"obj/changjian",
                __DIR__"obj/gangdao",
                __DIR__"obj/baozi",
                __DIR__"obj/beixin",
                __DIR__"obj/goldring",
                __DIR__"obj/flower_shoe",
	}) );
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

