inherit NPC;
void create()
{
        set_name("赤老温", ({"chilaowen", "wen" }));
        set("title", "大漠四杰-白狼" );
                    set("gender", "男性");
                   set("age", 36 );
                   set("str", 29 );
                   set("int", 15 );
                   set("long",                   

"这赤老温是大漠四杰里最小的，也是最彪悍的。只见他满
 脸满手都是刀疤，面红似血，令人望而生畏。当年铁木真
 有难，便是他救了铁木真的性命。\n" );
                    set("combat_exp", 200000 );
                    set("attitude", "heroism" );
                    set("force", 1700 );
                    set("max_force", 1700 );
                    set("force_factor", 10 );
                    set_skill("parry", 140 );
                    set_skill("dodge", 130 );
                    set_skill("force", 120 );
                    set_skill("sword", 120 );                           
                    set_skill("unarmed", 140 );
                    set("inquiry", ( [
                           "铁木真": "希望大汉早日统一蒙古，南灭大金国。\n"                                                                                                                                                                                                              
        ]));
              setup();
}
