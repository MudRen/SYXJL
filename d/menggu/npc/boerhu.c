inherit NPC;
void create()
{
        set_name("博尔忽", ({"boerhu", "hu" }));
        set("title", "大漠四杰-灰狼" );
                    set("gender", "男性");
                   set("age", 37 );
                   set("str", 25 );
                   set("int", 17 );
                   set("long",                   

"博尔忽身材短小精悍，脚步矫捷，是赤狼博尔术的兄
 弟，与博尔术等并称大漠四杰。别看他战场上是个万
 夫难敌的猛汉，其实十分细心，所以铁木真让四子拖
 雷跟随他学习武艺。\n");
                    set("combat_exp", 200000 );
                    set("attitude", "heroism" );
                    set("force", 1600 );
                    set("max_force", 1600 );
                    set("force_factor", 10 );
                    set_skill("parry", 130 );
                    set_skill("dodge", 130 );
                    set_skill("force", 120 );
                    set_skill("sword", 120 );                           
                    set_skill("unarmed", 120 );
                    set("inquiry", ( [
                           "铁木真": "你看这草原上的牛羊总有一天都会是大汉的，草原上的人民都会                                                                                                                                                                                                  过上丰衣足食的幸福生活。\n"                
         ]));
              setup();
}           
