// xihuazi.c (kunlun)



inherit NPC;

inherit F_MASTER;



void create()

{

       set_name("������", ({ "xi huazi", "xi" }));

       set("long",

               "���ǰ���浵�ͽ�ܣ�������ף�����ʮ�ֱ��ꡣ\n");

       set("gender", "����");

       set("unique", 1);

       set("age", 26);

       set("attitude", "peaceful");

       set("shen_type", -1);

       set("str", 30);

       set("int", 23);

       set("con", 25);

       set("dex", 28);



       set("max_qi", 700);

       set("max_jing", 400);

       set("neili", 600);

       set("max_neili", 600);

       set("jiali", 30);

       set("combat_exp", 50000);

       set("score", 5000);



       set_skill("force", 50);

       set_skill("xuantian-wuji", 50);

       set_skill("dodge", 54);

       set_skill("kunlun-shenfa", 54);

       set_skill("parry", 50);

       set_skill("sword", 52);

       set_skill("liangyi-jian", 52);

       set_skill("throwing", 50);



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



