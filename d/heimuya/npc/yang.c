#include <ansi.h>
inherit NPC;

void create()
{
        set_name("杨莲亭", ({ "yang lianting", "yang",}));
        set("long", 
"此人身形魁梧，满脸胡须，形貌极为雄健
威武，可下盘虚浮，看来无甚内功。\n");
        set("title",HIW"日月神教总管"NOR);        
        set("gender", "男性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 22);
        set("con", 21);
        set("dex", 19);
        
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 80000);
        set("shen", -1000);


       
        set_skill("tmzhang",50);
        set_skill("pmshenfa",50);
         set_skill("tmdafa",50);

        map_skill("unarmed", "tmzhang");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("日月神教",3,"弟子");
        setup();
}
