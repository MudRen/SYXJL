inherit NPC;
inherit F_DEALER;
//inherit F_VENDOR_SALE;

void create()
{
//        reload("huoji");
        set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
//        set("shop_id",({"huoji"}));
//        set("shop_title","ҩ�̻��");
        set("str", 20);
        set("gender", "����");
        set("age", 18);
        set("long", "��ʮ��ǿ׳������ȥ�Ἰ���书����ҩ����������ͷͷ�ǵ���\n");
        set("combat_exp", 1000);
        set("qi",400);
        set("max_qi",400);
        set("jing",200);
        set("max_jing",200);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/city/obj/jinchuang",
                "/d/city/obj/yangjing",
//                "/d/city2/obj/gaoyao",
        }));
//        set_skill("unarmed", 60);
//        set_skill("dodge", 60);
//        set_skill("parry", 60);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 5);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

