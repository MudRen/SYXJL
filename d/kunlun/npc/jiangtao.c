// jiangtao.c (kunlun)



#include "/quest/quest.h"
inherit NPC;

inherit F_MASTER;



void create()

{

        set_name("蒋涛", ({ "jiang tao", "jiang"}));

        set("long",

                "他穿青色长袍，背上斜插长剑，二十八九岁年纪。\n"

                "脸罩寒霜，一副要惹事生非的模样。\n");

        set("gender", "男性");

        set("unique", 1);

        set("age", 20);

        set("attitude", "heroism");

        set("shen_type", 1);

        set("str", 26);

        set("int", 24);

        set("con", 24);

        set("dex", 25);



        set("max_qi", 600);

        set("max_jing", 500);

        set("neili", 500);

        set("max_neili", 500);

        set("jiali", 30);

        set("combat_exp", 150000);

        set("score", 10000);



        set_skill("force", 50);

        set_skill("xuantian-wuji", 50);

        set_skill("dodge", 55);

        set_skill("kunlun-shenfa", 55);

        set_skill("parry", 50);

        set_skill("sword", 60);

        set_skill("liangyi-jian", 60);

        set_skill("strike", 60);

        set_skill("kunlun-zhang", 60);



        map_skill("force", "xuantian-wuji");

        map_skill("dodge", "kunlun-shenfa");

        map_skill("sword", "liangyi-jian");

        map_skill("strike", "kunlun-zhang");

        prepare_skill("strike", "kunlun-zhang");



        create_family("昆仑派", 5, "弟子");

        setup();

        carry_object("/d/kunlun/obj/sword")->wield();

        carry_object("/d/kunlun/obj/cloth")->wear();

}



void attempt_apprentice(object ob)

{

         if(ob->query("appren_hezudao", 1) == 1) {

        command("say 师祖怎敢开如此玩笑，晚辈却是万万不敢的！");

        return;

        }



        command("say 好吧，我就收下你，教你一些皮毛功夫。");

        command("recruit " + ob->query("id"));

}



