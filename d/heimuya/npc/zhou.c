#include <ansi.h>
inherit NPC;

void create()
{
        set_name("周孤桐", ({ "zhou gutong", "zhou",}));
        set("nickname", "桐柏双奇");        
        set("long", 
"他那一张品黄的脸上对你发出一阵阴笑。\n");
        set("title",HIM"日月神教朱雀堂舵主"NOR);        
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        
               set("max_qi", 700);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen", -1000);


       
        set_skill("tmzhang",100);
        set_skill("tmjian",100);
        set_skill("tmdao",100);        
        set_skill("pmshenfa",100);
         set_skill("tmdafa",100);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("日月神教",3,"弟子");
        setup();
 carry_object(__DIR__"obj/gangzhang")->wield();
        carry_object(__DIR__"obj/cloth")->wear();        
}
