                                   //  meng ������ -by duanfei 
inherit NPC;
 
void create()
{
        set_name("������", ({ "meng zhengpeng", "meng" }));
        set("nickname", "��ﵶ����");
        set("long", 
        "��ﵶ�����ţ�һ������˵��Ϊ�˵á�\n");
        set("gender", "����");
        set("age", 52);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 27);
        
        set("max_qi", 1200);
        set("max_jing", 1200);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 20);
        set("combat_exp", 480000); 
         
         set_skill("force", 100);
         set_skill("yijin-jing", 100);
         set_skill("dodge", 120);
  

        set_skill("shaolin-shenfa", 100 + random(20));
        set_skill("cuff", 120 + random(20));
        set_skill("blade", 140);
        set_skill("jingang-quan", 120);
        set_skill("parry", 140);
        set_skill("murong-daofa", 140);
        set_skill("literate", 90);
        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "murong-daofa");
        map_skill("blade", "murong-daofa");
        prepare_skill("cuff", "jingang-quan");

        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
        add_money("silver", 20);
}
#include "/quest/gfjob/npc/npc.h"

