inherit NPC;
#include "biaotou.h"
void create()
{
        set_name("��ͷ", ({ "biao tou" }));
        set("long", "��ԭ�������ɵ��ӣ�����������ͷ��");
        set("age", random(20) + 20);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);

        set("max_qi", 300);
        set("eff_qi", 300);
        set("qi", 300);
        set("max_jing", 100);
        set("jing", 100);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);

        set("combat_exp", 50000);
        set("score", 500000);
        set("shen", 0);

        set_skill("cuff",   180);
        set_skill("sword",  180);
        set_skill("dodge",  180);
        set_skill("unarmed",180); 
        set_skill("force",  180);
        set_skill("parry",  180);
        set_skill("zixia-shengong", 180);
        set_skill("huashan-jianfa",  180);
        set_skill("huashan-shenfa",  180);

        map_skill("dodge", "huashan-shenfa");
        map_skill("force","zixia-shengong");
        map_skill("sword","huashan-jianfa");
        map_skill("parry","huashan-jianfa");

        setup(); 
        add_money("gold", 2);          
        carry_object("/clone/misc/cloth")->wear();        
       carry_object("/clone/weapon/changjian")->wield();
      }


