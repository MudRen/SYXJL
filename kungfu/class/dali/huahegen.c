// huahegen.c  华和茛
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("华和茛", ({ "hua hegen", "hua", "hegen" }));
        set("title", "大理官员");
        set("nickname", HIC "司徒" NOR );
        set("long", "他就是大理的司徒。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 10);
        set("combat_exp", 50000);
        set("score", 2000);
        set("env/wimpy", 5);

        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("cuff", 50);
        set_skill("kurong-changong", 50);
        set_skill("literate", 200);

        map_skill("force", "kurong-changong");
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("gold",10 );
}
