//  asan����
 
inherit NPC;
 
void create()
{
	set_name("����", ({ "a san", "a" }));
//	set("nickname", "");
	set("long", 
        "����ŵĸ��֣�һ���⹦�����뻯�����ּ���ݶ���\n");
	set("gender", "����");
	set("age", 46);
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 35);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 120);
	set("combat_exp", 1400000); 
	 
         set_skill("force", 160);
         set_skill("yijin-jing", 180);
         set_skill("dodge", 190);
         set_skill("longzhua-gong", 160);
         set_skill("parry", 190);
        set_skill("shaolin-shenfa", 190);
        set_skill("cuff", 180);
        set_skill("claw", 180);
        set_skill("jingang-quan", 180);
        set_skill("literate", 150);
        set_skill("yizhi-chan", 180);
        set_skill("finger", 150);
        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "yizhi-chan");
         map_skill("claw", "longzhua-gong");
  	map_skill("parry", "jingang-quan");
  	prepare_skill("claw", "longzhua-gong");
        prepare_skill("finger", "yizhi-chan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}
#include "/quest/gfjob/npc/npc.h"
