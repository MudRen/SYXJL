inherit NPC;
void create()
{        
        set_name("木华黎", ({"muhuali", "mu" }));
                   set("title", "大漠四杰-青狼");
                   set("gender", "男性");
                   set("age", 37 );
                   set("str", 27 );
                   set("int", 18 );
                   set("long",

"这个相貌温雅，脸色白净的年轻人便是成吉思汗
 铁木真的猛将，人称大漠四杰之一的木华黎，他
 不但武功高强，英勇善战，而且是位颇有心计，
 善于用兵的将军，铁木真对他十分器重。\n");
                    set("combat_exp", 200000 );
                    set("attitude", "heroism");
                    set("neili", 1800 );
                    set("max_neili", 1800 );
                    set("force_factor", 10 );
                    set_skill("parry", 130 );
                    set_skill("dodge", 130 );
                    set_skill("force", 120 );
                    set_skill("sword", 120 );
                    set_skill("unarmed", 130 );
                    set("inquiry", ( [
                           "铁木真":"大汉是我们最敬重的人，总有一天他会以成吉思汗的名义统治这片                    
                    宽广美丽的草原！\n" 
         ]));
              setup();
}
