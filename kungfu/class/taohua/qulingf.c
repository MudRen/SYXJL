#include <ansi.h>
#include "/quest/quest.h"
inherit NPC;

void create()
{
        set_name("曲灵风", ({ "quling feng", "feng", "quling" }) );

        set("nickname",  RED "大弟子" NOR);
        set("gender", "男性");
        set("age", 40);
        set("long",
            "他是黄药师的四弟子，是桃花岛四大弟子\n"
            "“陈、梅、曲、陆”中的曲灵风，最得\n"
            "黄药师宠爱，资质最好，功夫也最高，\n"
            "琴棋书画无所不能。他看起来二十多岁，\n"
            "相貌俊美，面如冠玉， 中等身材。\n" 
        );
        set("attitude", "peaceful");

        set("str", 20);
        set("con", 20);
        set("int", 20);
        set("dex", 20);
        set("per", 28);

        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("max_qi", 2000);
        set("max_jing", 1000);

        set("combat_exp", 500000);
        set("score", 20000);
        


        set_skill("force", 110);
        set_skill("bibo-shengong", 110);
        set_skill("dodge", 110);
        set_skill("anying-fuxiang", 110);
        set_skill("strike", 100);
        set_skill("luoying-zhang",110);
        set_skill("parry", 110);
        set_skill("sword", 100);
        set_skill("luoying-shenjian", 100);
        set_skill("literate", 50);
        set_skill("qimen-wuxing", 100);

        map_skill("force", "bibo-shengong");
        map_skill("dodge", "anying-fuxiang");
        map_skill("strike","luoying-zhang");
        map_skill("parry", "luoying-shenjian");
        map_skill("sword", "luoying-shenjian");
        
        prepare_skill("strike", "luoying-zhang");

        create_family("桃花岛", 2, "大弟子");
        

        setup();
        carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/misc/cloth")->wear();
}




