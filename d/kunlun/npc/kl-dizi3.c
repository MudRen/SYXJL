// kunlun-dizi3.c (kunlun)



inherit NPC;



void create()

{

        set_name("À¥ÂØÅÉµÜ×Ó", ({ "dizi"}));

        set("long",

                "Ëû¿´ÆğÀ´°òÀ«ÑüÔ²£¬ËÆºõÁ·¹ıÒ»µãÎä¹¦¡£\n");

        set("gender", "ÄĞĞÔ");

        set("age", 25);

        set("attitude", "heroism");

        set("shen_type", 1);

        set("str", 25);

        set("int", 20);

        set("con", 20);

        set("dex", 24);



        set("max_qi", 350);

        set("max_jing", 250);

        set("neili", 400);

        set("max_neili", 400);

        set("jiali", 10);

        set("combat_exp", 15000);

        set("score", 4000);



        set_skill("force", 30);

        set_skill("xuantian-wuji", 30);

        set_skill("dodge", 40);

         set_skill("kunlun-shenfa", 40);

        set_skill("parry", 30);

        set_skill("sword", 30);



        map_skill("force", "xuantian-wuji");

        map_skill("dodge", "kunlun-shenfa");



        create_family("À¥ÂØÅÉ", 5, "µÜ×Ó");

        setup();

        carry_object("/d/kunlun/obj/sword")->wield();

        carry_object("/d/kunlun/obj/cloth.c")->wear();

}



