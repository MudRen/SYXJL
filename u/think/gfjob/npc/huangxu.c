// huangxu daoren 黄须道人
inherit NPC;
 
void create()
{
        set_name("黄须道人", ({ "huangxu daoren", "daoren" }));
//      set("nickname", "");
        set("long", 
        "武当的叛徒，为人奸诈，常常干些坏事。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 27);
        
        set("max_qi", 500);
        set("max_jing", 400);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 10);
        set("combat_exp", 75000 + random(40000)); 
         
         set_skill("force", 60);
         set_skill("taiji-shengong", 70);
         set_skill("dodge", 60);
  

        set_skill("tiyunzong", 30 + random(50));
        set_skill("unarmed", 40 + random(50));
        set_skill("taiji-shengong", 40 + random(50));        
        set_skill("parry", 40 + random(50));
        set_skill("taiji-quan", 30 + random(50));
        set_skill("literate", 20);
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
#include "/quest/gfjob/npc/npc.h"
