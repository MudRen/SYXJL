#include <ansi.h>
inherit NPC;

void create()
{
        set_name("吴柏英", ({ "wu baiying", "wu",}));
        set("long", 
"这女子肌肤微黑，双眼极小，黑如点漆。\n");
        set("nickname","桐柏双奇");
        set("title",HIW"日月神教白虎堂舵主"NOR);        
        set("gender", "女性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
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
        set_skill("rybian",160);
       
        map_skill("unarmed", "tmzhang");
        map_skill("whip", "rybian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("日月神教",3,"弟子");
        setup();
 carry_object(__DIR__"obj/changbian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();        
}
