#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ɣ����", ({ "sang sanniang", "sang",}));
        set("long", 
"һ����ò��������긾�ˣ���ɱ�������ĺ���������������\n");
        set("title",HIW"������̰׻�����"NOR);        
        set("gender", "Ů��");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
                set("max_qi", 700);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("shen", -1000);


       
        set_skill("tmzhang",100);
        set_skill("tmjian",100);
        set_skill("tmdao",100);        
        set_skill("pmshenfa",100);
         set_skill("tmdafa",100);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("�������",3,"����");
            set("no_get",1);
        setup();
 carry_object("/d/city/npc/obj/gangdao")->wield();
        carry_object("/d/city/npc/obj/cloth")->wear();        
}
