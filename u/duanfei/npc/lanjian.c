// /NPC lanjian.c



#include <ansi.h>



inherit NPC;



void create()

{

        set_name("����", ({ "lan jian", "lan"}));

        set("long",

            "���Ǹ���ò毺õ�Ů��, ��������,\n"+

            "�������, �������.\n"+

            "���ܾ������ļ�����.\n");

        set("gender", "Ů��");

        set("age", 18);

        set("shen_type",1);

        set("attitude", "peaceful");



        set("str", 25);

        set("int", 25);

        set("con", 25);

        set("dex", 25);

        set("per", 24);


        set("qi", 1000);

        set("max_qi", 1000);

        set("jing", 500);

        set("max_jing", 500);

        set("neili", 1000);

        set("max_neili", 1000);

        set("jiali", 20);



        set("combat_exp", 50000);

        set("score", 10000);

        set_skill("force", 100);

        set_skill("unarmed", 100);

        set_skill("dodge", 100);

        set_skill("parry", 100);

        set_skill("hand",100);

        set_skill("strike", 100);

        set_skill("sword",100);

        set_skill("literate",100);



        set_skill("zhemei-shou",100);

        set_skill("liuyang-zhang",100);

        set_skill("tianyu-qijian",100);

        set_skill("yueying-wubu",100);

        set_skill("bahuang-gong", 100);



        map_skill("force", "bahuang-gong");

        map_skill("strike","liuyang-zhang");

        map_skill("dodge", "yueying-wubu");

        map_skill("unarmed", "liuyang-zhang");

        map_skill("hand", "zhemei-shou");

        map_skill("parry", "liuyang-zhang");

        map_skill("sword", "tianyu-qijian");



        create_family("���չ�",3,"����");

        setup();

        carry_object("/d/lingjiu/obj/qingyi")->wear();

            carry_object("/d/lingjiu/obj/doupeng")->wear();

        carry_object("/clone/weapon/changjian")->wield();

        add_money("silver",15);

}
