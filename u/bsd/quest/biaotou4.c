inherit NPC;
#include "biaotou.h"
void create()
{
        set_name("��ͷ", ({ "biao tou" }));
        set("long", "��ԭ�Ƕ����ɵ��ӣ�����������ͷ��");
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

        set_skill("linji-zhuang", 160);
        set_skill("fuliu-jian", 160);
        set_skill("literate", 160);
        set_skill("sword", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("force", 160);
        set_skill("anying-fuxiang", 160);

        map_skill("force", "linji-zhuang");
        map_skill("sword", "fuliu-jian");
        map_skill("parry", "fuliu-jian");
        map_skill("dodge", "anying-fuxiang");
        setup(); 
        add_money("gold", 2);        
        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();        
      }



