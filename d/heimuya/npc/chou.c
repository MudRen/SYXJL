#include <ansi.h>
inherit NPC;

void create()
{
        set_name("仇松年", ({ "chou songnian", "chou",}));
        set("nickname", "长发头陀");        
        set("long", 
"这头陀长发垂肩，头上戴着一个闪闪发光的铜箍，束着长发。\n");
        set("title",RED"日月神教朱雀堂旗主"NOR);        
        set("gender", "男性");
        set("age", 40);
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
        set("combat_exp", 500000);
        


        set_skill("wuchang-zhang",100);
        set_skill("tmzhang",100);
        set_skill("tmjian",100);
        set_skill("tmdao",100);        
        set_skill("pmshenfa",100);
        set_skill("tmdafa",100);

        map_skill("unarmed", "tmzhang");
        map_skill("staff", "wczhang");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("日月神教",3,"弟子");
            set("no_get",1);
        setup();
 carry_object(__DIR__"obj/gangzhang")->wield();
        carry_object(__DIR__"obj/cloth")->wear();        

}
