#include <ansi.h>
inherit NPC;

void create()
{
        set_name("˾���", ({ "si mada", "si",}));
        set("long", 
"�����Ŀ���֮�������˰���������߶�
ʱ���Ų�����֮���أ������ذ嶼Ϊ֮�𶯡�\n");
        set("title",GRN"������������ö���"NOR);        
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        
        set("max_qi", 700);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 500000);



       
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
        
        map_skill("unarmed", "tmzhang");
        create_family("�������", 3, "����");

        setup();
}

