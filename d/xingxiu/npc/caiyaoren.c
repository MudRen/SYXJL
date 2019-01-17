// npc: /d/xingxiu/npc/caiyaoren.c

// Jay 3/18/96



inherit NPC;



void create()

{

        set_name("采药人", ({ "caiyao ren", "caiyao", "ren" }));

        set("gender", "男性");

        set("age", 30 + random(10));



        set("long", "一个辛苦工作的采药人。\n");

        set("attitude", "friendly");



       set("combat_exp", 21000);

        set("shen_type", 1);



        set_skill("unarmed", 20);

        set_skill("dodge", 20);

        set_skill("hammer", 20);

        set("apply/attack", 45);

        set("apply/defense", 45);

        set("apply/damage", 35);

        setup();

        carry_object(__DIR__"obj/xuelian");

        add_money("coin", 50);

        carry_object(__DIR__"obj/yaochu")->wield();

}



