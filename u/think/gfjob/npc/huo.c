//  huo
// by duanfei
 
inherit NPC;
 
void create()
{
        set_name("��Ԫ��", ({ "huo yuanfeng", "huo" }));
        set("long", 
        "һ����������������ײУ�һ�������˷ǳ����¡�\n");
        set("gender", "����");
        set("age", 36);
        set("attitude", "peaceful");
        set("str", 38);
        set("int", 20);
        set("con", 25);
        set("dex", 27);
        
        set("max_qi", 1800);
        set("max_jing", 1800);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 100);
        set("combat_exp", 700000); 
          
         set_skill("force", 165);
         set_skill("xuantian-wuji", 165);
         set_skill("dodge", 160);
  

        set_skill("kunlun-shenfa", 165);
        set_skill("strike", 160);
        set_skill("hanbing-mianzhang", 160);
        set_skill("parry", 160);
        set_skill("murong-daofa", 160);
        set_skill("blade", 150);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("blade", "murong-daofa");
        map_skill("strike", "hanbing-mianzhang");
        map_skill("parry", "hanbing-mianzhang");
        prepare_skill("strike", "hanbing-mianzhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
     
        add_money("silver", 100);
}
#include "/quest/gfjob/npc/npc.h"

