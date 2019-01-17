// zhanchun.c (kunlun)



inherit NPC;

inherit F_MASTER;



void create()

{

        set_name("ղ��", ({ "zhan chun", "zhan", "chun" }));

        set("long",

                "���Ǻ�̫����ϲ���ĵ��ӣ����õ�Ҳ��Ϊ������\n");

        set("gender", "Ů��");

        set("unique", 1);

        set("age", 24);

        set("attitude", "friendly");

        set("shen_type", 1);

        set("str", 25);

        set("int", 24);

        set("con", 28);

        set("dex", 26);



        set("max_qi", 600);

        set("max_jing", 400);

        set("neili", 500);

        set("max_neili", 500);

        set("jiali", 30);

        set("combat_exp", 50000);

        set("score", 5000);



        set_skill("force", 30);

        set_skill("xuantian-wuji", 30);

        set_skill("dodge", 34);

        set_skill("kunlun-shenfa", 34);

        set_skill("parry", 30);

        set_skill("sword", 32);

        set_skill("liangyi-jian", 35);

        set_skill("throwing", 30);



        map_skill("force", "xuantian-wuji");

        map_skill("dodge", "kunlun-shenfa");

        map_skill("sword", "liangyi-jian");



        create_family("������", 5, "����");

        setup();

        carry_object("/d/kunlun/obj/sword")->wield();

        carry_object("/d/kunlun/obj/cloth")->wear();

}



void attempt_apprentice(object ob)

{

                command("say ������㹦���ĸ�ָ���㣬"+RANK_D->query_respect(ob)+

                                  "����ȥ����ʦ���ɡ�");

 }



