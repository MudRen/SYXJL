// huoji. ҩ�̻��

inherit NPC;
inherit F_DEALER;

string ask_me();
void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "����ƽ��ҽ������������æ�ġ�\n");
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
        set("inquiry", ([
                "����" : (: ask_me :),
        ]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
}
string ask_me()
{
        this_player()->add("gold", -5);
}
