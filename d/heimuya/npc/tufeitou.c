#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"土匪头"NOR, ({ "tufei tou","tou" }) );
        set("gender", "男性");
        set("age", 45);
        set("long",
                "他是千古石的守卫，这家伙满脸杀气，一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 120000);
        set("shen_type", -1);
        set("attitude", "aggressive");

        set("apply/attack",  30);
        set("apply/defense", 30);

        set("chat_chance", 5);
        set("chat_msg", ({
                "土匪头嘿嘿地冷笑道:你竟敢闯到这里来，今天你就别想从这里活着出去了!\n",
        }) );
       set_skill("dugu-jiujian", 80);
        set_skill("sword", 80);
        set_skill("unarmed", 80);
        set_skill("parry", 150);
        set_skill("dodge", 80);
        map_skill("sword", "dugu-jiujian");
        map_skill("parry", "dugu-jiujian");
        setup();
        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10000);
}
