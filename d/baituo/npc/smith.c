// smith.c



//inherit NPC;

//inherit F_DEALER;
inherit F_VENDOR_SALE;



void create()

{

        set_name("����", ({ "tiejiang", "smith" }));

	set("shen_type", 1);



        set("gender", "����" );

        set("age", 33);

        set("long", "�������ú���䤱��ش�����\n");



        set("combat_exp", 500);

	set("attitude", "friendly");

        set("vendor_goods",({

                   __DIR__"obj/dadao",

//                   "/d/baituo/obj/tiezhang",

        }) );



	setup();
        carry_object("/d/city/obj/cloth")->wear();


}



void init()

{

         add_action("do_vendor_list", "list");

}



