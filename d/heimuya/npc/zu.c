#include <ansi.h>
inherit NPC;

void create()
{
        set_name("祖千秋", ({ "zu qianqiu", "zu",}));
        set("nickname","黄河老祖");
        set("long", 
"只见他面皮焦黄，双目无神，疏疏落落有几根
胡子，身材颇瘦削，却挺着个大肚子。\n");
        set("age", 80);        
        set("title",HIM"日月神教风雷堂坛主"NOR);       
        set("gender", "男性");
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen", -1000);


       
        set_skill("tmzhang",100);
        set_skill("pmshenfa",100);
         set_skill("tmdafa",100);

        map_skill("unarmed", "tmzhang");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("日月神教",3,"弟子");
        setup();
}
