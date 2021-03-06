#include <ansi.h>
inherit NPC;

void create()
{
        set_name("张夫人", ({ "zhang furen", "zhang",}));
        set("long", 
"这女子肌肤微黄，双眼极大，黑如点漆。
她掌管日月教在苗疆的下属“五毒教”，
使毒手法诡秘奇特，令人防不胜防。\n");
        set("title",HIW"日月神教白虎堂旗主"NOR);        
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


       set_skill("wuchang-zhang",100);
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
        map_skill("staff", "wuchang-zhang");
create_family("日月神教",3,"弟子");
        setup();
 carry_object(__DIR__"obj/gangzhang")->wield();
        carry_object(__DIR__"obj/cloth")->wear();        
}
