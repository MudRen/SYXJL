// daobaifeng.c

inherit NPC;

void create()
{
        set_name("刀白凤", ({ "dao baifeng", "dao", "baifeng" }));
        set("title", "镇南王妃");
        set("age", 38);
        set("gender", "女性");
        set("long", "这是一位女尼，身着一身灰色的道袍，但仍掩饰不住她的娇美。\n");
        set("attitude", "peaceful");

        set("age", 38);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 1000000);

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("tiannan-bufa", 110);
        set_skill("strike", 110);
        set_skill("wuluo-zhang", 110);
        set_skill("parry", 110);
        set_skill("literate", 110);
        set_skill("kurong-changong", 100);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bufa");
        map_skill("strike", "wuluo-zhang");
        map_skill("parry", "wuluo-zhang");
        prepare_skill("strike", "wuluo-zhang");

        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}
