//xiao-nigu.c ....angle

inherit NPC;

#include <ansi.h>



void create()

{       set_name("小尼姑", ({ "xiao nigu", "nigu" })); 

        set("gender", "女性");

        set("age", 16);

        set("str", 20);

        set("dex", 20); 

        set("per", 30);   

set("long", "这是个美丽的小尼姑，满脸还留有几份稚气，甚是可爱！\n");

        set("combat_exp", 12000);

        set("shen_type", 1);

        set("attitude", "friendly"); 

       

        set_skill("unarmed", 45);

        set_skill("dodge", 45);

        set_skill("parry", 45);

        set_skill("force", 45);



        set_temp("apply/attack", 25);

        set_temp("apply/defense", 25);

        set_temp("apply/armor", 25);

        set_temp("apply/damage", 15);



        setup();

        carry_object("/clone/misc/cloth")->wear();  

} 





