//xiao-nigu.c ....angle

inherit NPC;

#include <ansi.h>



void create()

{       set_name("С���", ({ "xiao nigu", "nigu" })); 

        set("gender", "Ů��");

        set("age", 16);

        set("str", 20);

        set("dex", 20); 

        set("per", 30);   

set("long", "���Ǹ�������С��ã����������м������������ǿɰ���\n");

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





